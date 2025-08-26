#pragma once
#include "Core/Grid/Grid.h"
#include "Core/Graphics/Color.h"
#include "raylib.h"

class GridRenderer {
public:
    GridRenderer(int cellSize);

    void Draw(const Grid& grid, int offset_x, int offset_y) const;

private:
    int _cellSize;
};