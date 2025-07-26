/**
 * @file block.cpp
 * @brief Triển khai lớp Block, đại diện cho một khối trong trò chơi Tetris.
 * 
 * File này định nghĩa cách vẽ khối, di chuyển, xoay, và tính toán vị trí của các ô (cell) trong khối.
 */

#include "block.h"

/**
 * @brief Khởi tạo một khối Block với giá trị mặc định.
 * 
 * Thiết lập kích thước ô, trạng thái xoay ban đầu, danh sách màu sắc, 
 * và vị trí offset hàng và cột cho khối.
 */
Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

/**
 * @brief Vẽ khối Block lên màn hình.
 * 
 * @param offsetX Vị trí dịch chuyển theo trục X (pixel).
 * @param offsetY Vị trí dịch chuyển theo trục Y (pixel).
 */
void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

/**
 * @brief Di chuyển khối theo hàng và cột.
 * 
 * @param rows Số hàng cần di chuyển.
 * @param columns Số cột cần di chuyển.
 */
void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

/**
 * @brief Lấy danh sách các vị trí cell thực tế của khối dựa trên trạng thái xoay và offset hiện tại.
 * 
 * @return std::vector<Position> Danh sách vị trí các ô trong khối.
 */
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

/**
 * @brief Xoay khối sang trạng thái tiếp theo.
 */
void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

/**
 * @brief Hoàn tác lần xoay gần nhất của khối.
 */
void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = static_cast<int>(cells.size()) - 1;
    }
}

/**
 * @brief Tính toán chiều rộng và chiều cao của khối trong trạng thái xoay hiện tại.
 * 
 * @return std::pair<int, int> Cặp {width, height} của khối.
 */
std::pair<int, int> Block::GetSize()
{
    std::vector<Position> tiles = cells[rotationState];
    int minRow = INT_MAX, maxRow = INT_MIN;
    int minCol = INT_MAX, maxCol = INT_MIN;

    for (const Position& p : tiles)
    {
        if (p.row < minRow) minRow = p.row;
        if (p.row > maxRow) maxRow = p.row;
        if (p.column < minCol) minCol = p.column;
        if (p.column > maxCol) maxCol = p.column;
    }

    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;
    return { width, height };
}
