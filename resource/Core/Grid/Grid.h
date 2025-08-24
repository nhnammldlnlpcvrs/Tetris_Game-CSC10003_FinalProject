#pragma once

#include <vector>
#include "Core/Graphics/Color.h" // Dùng Color tự định nghĩa, không phải raylib::Color
#include "Core/Position/Position.h" // Dùng Position tự định nghĩa, không phải raylib::Vector2
#include <algorithm>

class Grid {
public:
    Grid(int rows, int columns);

    bool IsCellOccupied(int row, int column) const;
    void SetCell(int row, int column, const Color& color);
    void ClearCell(int row, int column);
    int ClearFullLines();

    int GetRows() const;
    int GetColumns() const;
    const std::vector<std::vector<Color>>& GetCells() const;

    bool IsValidPosition(const std::vector<Position>& positions) const;
    bool HasBlockAtTop() const;

private:
    int _rows;
    int _columns;
    std::vector<std::vector<Color>> _cells;
};
