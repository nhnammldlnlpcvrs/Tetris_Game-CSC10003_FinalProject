#include "LBlock.h"

LBlock::LBlock() {
    _id = 2;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {orange};

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

std::vector<Color> LBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
