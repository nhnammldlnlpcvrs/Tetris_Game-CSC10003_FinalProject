/**
 * @file game.cpp
 * @brief Triển khai lớp Game - trung tâm xử lý logic chính cho trò chơi Tetris.
 * 
 * Lớp `Game` đóng vai trò quản lý:
 * - Logic điều khiển game loop (xử lý input, vẽ màn hình, xoay và di chuyển khối, kiểm tra va chạm, lock block, cập nhật điểm,...)
 * - Điều khiển trạng thái trò chơi: đang chơi, kết thúc, khởi động lại
 * - Quản lý khối hiện tại và khối tiếp theo
 * - Giao tiếp với lưới `Grid`, hệ thống âm thanh `AudioService` và các khối `Block`
 * 
 * Các chức năng nổi bật:
 * - Tạo block ngẫu nhiên không lặp
 * - Ghi/đọc điểm cao nhất từ file
 * - Xử lý va chạm, xoay block hợp lệ
 * - Tính điểm theo số dòng được xóa và soft drop
 * - Tích hợp âm thanh khi xoay hoặc xóa dòng
 * 
 */

#include "game.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <random>

const std::string BEST_SCORE_FILE = "../assets/best_score.txt";

void Game::LoadBestScore() {
    std::ifstream file(BEST_SCORE_FILE);
    if (file.is_open()) {
        file >> bestScore;
        file.close();
    } else {
        bestScore = 0;
    }
}

void Game::SaveBestScore() {
    if (score > bestScore) {
        bestScore = score;
        std::ofstream file(BEST_SCORE_FILE);
        if (file.is_open()) {
            file << bestScore;
            file.close();
        } else {
            std::cerr << "Error: Can't save best score .\n";
        }
    }
}

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
    audioService = std::make_shared<AudioService>();

    LoadBestScore();
}

std::shared_ptr<AudioService> Game::GetAudioService()
{
    return audioService;
}

Game::~Game() = default;

std::unique_ptr<Block> Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    std::unique_ptr<Block> block = std::move(blocks[randomIndex]);
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<std::unique_ptr<Block>> Game::GetAllBlocks()
{
    std::vector<std::unique_ptr<Block>> result;
    result.push_back(std::make_unique<IBlock>());
    result.push_back(std::make_unique<JBlock>());
    result.push_back(std::make_unique<LBlock>());
    result.push_back(std::make_unique<OBlock>());
    result.push_back(std::make_unique<SBlock>());
    result.push_back(std::make_unique<TBlock>());
    result.push_back(std::make_unique<ZBlock>());
    return result;
}

void Game::Draw()
{
    grid.Draw();
    currentBlock->Draw(11, 11);

    int boxX = 630;
    int boxY = 310;
    int boxWidth = 170;
    int boxHeight = 180;

    auto size = nextBlock->GetSize();
    int blockPixelWidth = size.first * 30;
    int blockPixelHeight = size.second * 30;

    int offsetX = boxX + (boxWidth - blockPixelWidth) / 2 - 90;
    int offsetY = boxY + (boxHeight - blockPixelHeight) / 2;

    if (nextBlock->id == 4) {
        offsetX -= 27; // Adjust for OBlock offset
    }
    nextBlock->Draw(offsetX, offsetY);
}



void Game::HandleInput()
{   
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    case KEY_SPACE:
        HardDrop();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock->Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock->Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock->Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::HardDrop()
{
    if (!gameOver)
    {
        while (true)
        {
            currentBlock->Move(1, 0);
            if (IsBlockOutside() || BlockFits() == false)
            {
                currentBlock->Move(-1, 0);
                LockBlock();
                break;
            }
        }
    }
    audioService->PlayRotateSound();
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if (!gameOver)
    {
        currentBlock->Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->UndoRotation();
        }
        else
        {
            audioService->PlayRotateSound();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock->id;
    }
    currentBlock = std::move(nextBlock);
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared > 0)
    {
        audioService->PlayClearSound();
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock->GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }
    score += moveDownPoints;
}
