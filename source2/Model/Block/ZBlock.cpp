#include "ZBlock.h"

ZBlock::ZBlock() {
    _id = 6;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = GetCellColors();

    _cells = {
        {0, {{0,0}, {0,1}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,0}, {1,1}, {2,0}}},
        {2, {{1,0}, {1,1}, {2,1}, {2,2}}},
        {3, {{0,2}, {1,1}, {1,2}, {2,1}}}
    };
}

std::unique_ptr<Block> ZBlock::Clone() const {
    return std::make_unique<ZBlock>(*this);
}
