#include "OBlock.h"

OBlock::OBlock() {
    _id = 3;
    _rotationState = 0;
    _rowOffset = 0;
    _columnOffset = 0;
_colors = {yellow};
   _cells = {
        {0, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {1, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {2, {{0,0}, {0,1}, {1,0}, {1,1}}},
        {3, {{0,0}, {0,1}, {1,0}, {1,1}}}
    };
}

std::unique_ptr<Block> OBlock::Clone() const {
    return std::make_unique<OBlock>(*this);
}

std::vector<Color> OBlock::GetCellColor() const {
    const auto& current_cells = _cells.at(_rotationState); // at() cho map const
    if (_colors.size() == 1) {
        return std::vector<Color>(current_cells.size(), _colors[0]);
    }
    return _colors;
}
