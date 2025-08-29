#pragma once

#include <ostream>

/**
 * @struct Position
 * @brief Đại diện cho một vị trí (hàng, cột) trong lưới trò chơi.
 */
struct Position {
    int row;
    int column;

    Position(int row = 0, int column = 0);

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Position& pos);
};
