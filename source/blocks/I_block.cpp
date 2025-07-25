#include "I_block.h"

IBlock::IBlock()
{
    id = 3;
    cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
    cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
    cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
    cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
    Move(-1, 3);
}

std::unique_ptr<IBlock> IBlock::Create()
{
    return std::make_unique<IBlock>();
}