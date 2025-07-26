#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

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

void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = static_cast<int>(cells.size()) - 1;
    }
}

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
