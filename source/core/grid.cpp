/**
 * @file grid.cpp
 * @brief Triển khai lớp Grid quản lý lưới trò chơi Tetris.
 *
 * File này chứa các phương thức để khởi tạo, hiển thị, kiểm tra và cập nhật lưới trò chơi Tetris.
 * Bao gồm vẽ các ô, kiểm tra va chạm, xoá hàng đầy và di chuyển hàng xuống.
 */

#include "grid.h"
#include <iostream>
#include "../data/colors.h"

/**
 * @brief Constructor mặc định. Khởi tạo kích thước lưới, giá trị ban đầu và màu sắc ô.
 */
Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

/**
 * @brief Gán toàn bộ ô trong lưới giá trị 0 (ô trống).
 */
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

/**
 * @brief In lưới hiện tại ra console (dùng để debug).
 */
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Vẽ lưới lên màn hình bằng thư viện đồ họa Raylib.
 */
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

/**
 * @brief Kiểm tra ô có nằm ngoài giới hạn lưới không.
 * @param row Hàng cần kiểm tra.
 * @param column Cột cần kiểm tra.
 * @return true nếu ô nằm ngoài lưới, false nếu không.
 */
bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

/**
 * @brief Kiểm tra ô có đang trống không.
 * @param row Hàng cần kiểm tra.
 * @param column Cột cần kiểm tra.
 * @return true nếu ô trống, false nếu đã có block.
 */
bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

/**
 * @brief Xoá các hàng đầy và dịch các hàng phía trên xuống.
 * @return Số lượng hàng đã xoá.
 */
int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

/**
 * @brief Kiểm tra một hàng đã đầy chưa (không còn ô trống).
 * @param row Hàng cần kiểm tra.
 * @return true nếu hàng đã đầy, false nếu chưa.
 */
bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Xoá toàn bộ ô trong một hàng.
 * @param row Hàng cần xoá.
 */
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

/**
 * @brief Di chuyển một hàng xuống dưới một số hàng nhất định.
 * @param row Hàng cần di chuyển.
 * @param numRows Số hàng cần dịch xuống.
 */
void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
