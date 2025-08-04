#include "LBlock.h"

LBlock::LBlock() {
    _id = 2;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = GetCellColors();

    _cells = {
        {0, {{0,2}, {1,0}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,1}, {2,1}, {2,2}}},
        {2, {{1,0}, {1,1}, {1,2}, {2,0}}},
        {3, {{0,0}, {0,1}, {1,1}, {2,1}}}
    };
}

std::unique_ptr<Block> LBlock::Clone() const {
    return std::make_unique<LBlock>(*this);
}
