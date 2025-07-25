#pragma once
#include "../core/grid.h"
#include "../data/block.h"
#include "../blocks/L_block.h"
#include "../blocks/J_block.h"
#include "../blocks/I_block.h"
#include "../blocks/O_block.h"
#include "../blocks/S_block.h"
#include "../blocks/T_block.h"
#include "../blocks/Z_block.h"
#include "../audio/audio_service.h"
#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    std::shared_ptr<AudioService> audioService;
    std::shared_ptr<AudioService> GetAudioService();

private:
    void MoveBlockLeft();
    void MoveBlockRight();
    std::unique_ptr<Block> GetRandomBlock();
    std::vector<std::unique_ptr<Block>> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

    Grid grid;
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Block> currentBlock;
    std::unique_ptr<Block> nextBlock;

};