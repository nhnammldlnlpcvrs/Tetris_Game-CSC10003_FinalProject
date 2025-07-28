#pragma once
#include <iostream>
#include <ostream>
/**
 * @file position.h
 * @brief Định nghĩa lớp Position dùng để biểu diễn tọa độ hàng và cột trong lưới Tetris.
 */

/**
 * @class Position
 * @brief Đại diện cho một vị trí trong lưới trò chơi.
 * 
 * Mỗi đối tượng Position chứa hai thành phần: hàng (`row`) và cột (`column`), được sử dụng để xác định vị trí của từng ô khối trong lưới.
 */
class Position
{
public:
    /**
     * @brief Constructor khởi tạo một Position với hàng và cột chỉ định.
     * @param row Vị trí hàng (0-based).
     * @param column Vị trí cột (0-based).
     */
    Position(int row, int column);

    /**
     * @brief Vị trí hàng trong lưới.
     */
    int row;

    /**
     * @brief Vị trí cột trong lưới.
     */
    int column;

    bool operator==(const Position& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Position& pos);
};
