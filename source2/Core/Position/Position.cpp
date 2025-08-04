#include "source2/Core/Position/Position.h"

constexpr Position::Position(int row, int column) : row(row), column(column) {}

bool Position::operator==(const Position& other) const {
    return row == other.row && column == other.column;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    return os << "(" << pos.row << ", " << pos.column << ")";
}
