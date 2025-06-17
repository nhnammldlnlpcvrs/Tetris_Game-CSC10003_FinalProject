#include "grid.h"
#include <iostream>


Grid::Grid() {
	_numRows = 20;
	_numCols = 10;
	_cellSize = 30;
	Initialize();
	_colors = _GetCellColors(); // Initialize the colors vector with cell colors
}

void Grid::Initialize() {
	for (int _row = 0; _row < _numRows; _row++) {
		for (int _col = 0; _col < _numCols; _col++) {
			grid[_row][_col] = 0; // Initialize all cells to 0
		}
	}
}

void Grid::Print() {
	for (int _row = 0; _row < _numRows; _row++) {
		for (int _col = 0; _col < _numCols; _col++) {
			// Print the value of each cell in the grid
			std::cout << grid[_row][_col] << " ";
		}
		std::cout << std::endl; // New line after each row
	}
}

void Grid::Draw() {
	for (int _row = 0; _row < _numRows; _row++) {
		for (int _col = 0; _col < _numCols; _col++) {
			int cellValue = grid[_row][_col];
			Color cellColor = _colors[cellValue]; // Get the color for the current cell
			DrawRectangle(_col * _cellSize+1, _row * _cellSize+1, _cellSize-1, _cellSize-1, _colors[cellValue]);
		}
	}
}

std::vector<Color> Grid::_GetCellColors() {
	Color darkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 255 };
	Color orange = { 226, 116, 17, 255};
	Color yellow = { 237, 234, 4, 255 };
	Color purple = { 166, 0, 247, 255 };
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };

	return {
		darkGrey, green, red, orange, yellow, purple, cyan, blue
	};
}