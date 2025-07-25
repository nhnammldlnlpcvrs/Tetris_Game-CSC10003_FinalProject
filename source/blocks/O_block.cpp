#include "O_block.h"

OBlock::OBlock()
{
    id = 4;
    cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
    Move(0, 4);
}

std::unique_ptr<OBlock> OBlock::Create()
{
    return std::make_unique<OBlock>();
}