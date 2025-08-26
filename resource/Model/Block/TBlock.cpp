#include "TBlock.h"

TBlock::TBlock() {
    _id = 5;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
    _colors = {green};

    _cells = {
        {0, {{0,1}, {1,0}, {1,1}, {1,2}}},
        {1, {{0,1}, {1,1}, {1,2}, {2,1}}},
        {2, {{1,0}, {1,1}, {1,2}, {2,1}}},
        {3, {{0,1}, {1,0}, {1,1}, {2,1}}}
    };
}

std::unique_ptr<Block> TBlock::Clone() const {
    return std::make_unique<TBlock>(*this);
}

std::vector<Color> TBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}