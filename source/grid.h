#pragma once
#include <vector>
#include "raylib.h"

class Grid {
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	int grid[20][10];
private:
	std::vector<Color> _GetCellColors();
	int _numRows;
	int _numCols;
	int _cellSize;
	std::vector<Color> _colors; // Vector to hold colors for each cell
};