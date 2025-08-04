#pragma once
#include "source2/Core/Grid/Grid.h"
#include "source2/Core/Graphics/Color.h"
#include "raylib.h"

class GridRenderer {
public:
    GridRenderer(int cellSize);

    void Draw(const Grid& grid, int offset_x, int offset_y) const;

private:
    int _cellSize;
};