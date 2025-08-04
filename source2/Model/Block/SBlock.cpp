#include "SBlock.h"

SBlock::SBlock() {
    _id = 4;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = GetCellColors();

    _cells = {
        {0, {{0,1}, {0,2}, {1,0}, {1,1}}},
        {1, {{0,0}, {1,0}, {1,1}, {2,1}}},
        {2, {{1,1}, {1,2}, {2,0}, {2,1}}},
        {3, {{0,1}, {1,0}, {1,1}, {2,0}}}
    };
}

std::unique_ptr<Block> SBlock::Clone() const {
    return std::make_unique<SBlock>(*this);
}
