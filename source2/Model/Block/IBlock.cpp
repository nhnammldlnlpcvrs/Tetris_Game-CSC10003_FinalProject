#include "IBlock.h"

IBlock::IBlock() {
    _id = 0;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = GetCellColors();
    _cells = {
        {0, { {1,0}, {1,1}, {1,2}, {1,3} }},
        {1, { {0,2}, {1,2}, {2,2}, {3,2} }},
        {2, { {2,0}, {2,1}, {2,2}, {2,3} }},
        {3, { {0,1}, {1,1}, {2,1}, {3,1} }}
    };
}

std::unique_ptr<Block> IBlock::Clone() const {
    return std::make_unique<IBlock>(*this);
}
