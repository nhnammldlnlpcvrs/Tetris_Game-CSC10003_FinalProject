#include "Grid.h"
#include "../source2/Core/Position/Position.h"  // Bổ sung để dùng Position

Grid::Grid(int rows, int columns)
    : _rows(rows), _columns(columns), _cells(rows, std::vector<Color>(columns, Color{0, 0, 0, 0})) {}

bool Grid::IsCellOccupied(int row, int column) const {
    return _cells[row][column].a != 0;
}

void Grid::SetCell(int row, int column, const Color& color) {
    _cells[row][column] = color;
}

void Grid::ClearCell(int row, int column) {
    _cells[row][column] = Color{0, 0, 0, 0};
}

int Grid::ClearFullLines() {  // sửa tên cho đúng với Grid.h
    int cleared = 0;
    for (int row = _rows - 1; row >= 0; --row) {
        bool full = true;
        for (int col = 0; col < _columns; ++col) {
            if (_cells[row][col].a == 0) {
                full = false;
                break;
            }
        }
        if (full) {
            _cells.erase(_cells.begin() + row);
            _cells.insert(_cells.begin(), std::vector<Color>(_columns, Color{0, 0, 0, 0}));
            ++cleared;
            ++row;  // Kiểm tra lại dòng mới đẩy xuống
        }
    }
    return cleared;
}

int Grid::GetRows() const {
    return _rows;
}

int Grid::GetColumns() const {
    return _columns;
}

const std::vector<std::vector<Color>>& Grid::GetCells() const {
    return _cells;
}

bool Grid::IsValidPosition(const std::vector<Position>& positions) const {
    for (const auto& pos : positions) {
        if (pos.row < 0 || pos.row >= _rows || pos.column < 0 || pos.column >= _columns)
            return false;
        if (IsCellOccupied(pos.row, pos.column))
            return false;
    }
    return true;
}

bool Grid::HasBlockAtTop() const {
    for (int col = 0; col < _columns; ++col) {
        if (_cells[0][col].a != 0) {
            return true;
        }
    }
    return false;
}
