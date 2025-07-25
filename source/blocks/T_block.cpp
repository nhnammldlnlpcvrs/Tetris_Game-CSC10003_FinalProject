#include "T_block.h"    


TBlock::TBlock()
{
    id = 6;
    cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
    cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
    Move(0, 3);
}

std::unique_ptr<TBlock> TBlock::Create()
{
    return std::make_unique<TBlock>();
}