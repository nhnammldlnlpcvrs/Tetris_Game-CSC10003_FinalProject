#include "position.h"

Position::Position(int row, int column)
{
    this->row = row;
    this->column = column;
}

bool Position::operator==(const Position& other) const {
    return row == other.row && column == other.column;
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    os << "(" << pos.row << ", " << pos.column << ")";
    return os;
}
