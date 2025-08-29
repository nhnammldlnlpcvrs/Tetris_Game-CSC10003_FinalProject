#include "Color.h"

// màu nền (id=0)
const Color darkGrey = { 26, 31, 40, 255 };

// 7 màu chuẩn cho 7 khối
const Color cyan   = { 21, 204, 209, 255 }; ///< I-block
const Color blue   = { 13, 64, 216, 255 };  ///< J-block
const Color orange = { 226, 116, 17, 255 }; ///< L-block
const Color yellow = { 237, 234, 4, 255 };  ///< O-block
const Color green  = { 47, 230, 23, 255 };  ///< S-block
const Color purple = { 166, 0, 247, 255 };  ///< T-block
const Color red    = { 232, 18, 18, 255 };  ///< Z-block

/**
 * @brief Trả về danh sách màu ứng với các loại cell trong game.
 *
 * Thứ tự màu:
 * - 0: màu nền (darkGrey)
 * - 1: I-block (cyan)
 * - 2: J-block (blue)
 * - 3: L-block (orange)
 * - 4: O-block (yellow)
 * - 5: S-block (green)
 * - 6: T-block (purple)
 * - 7: Z-block (red)
 *
 * @return Vector chứa các màu dùng trong trò chơi.
 */
std::vector<Color> GetCellColors()
{
    return { darkGrey, cyan, blue, orange, yellow, green, purple, red };
}

/**
 * @brief Lấy màu tương ứng với một block dựa trên ID.
 * @param id Chỉ số màu (0 = nền, 1-7 = các block).
 * @return Màu sắc tương ứng. Nếu id không hợp lệ thì trả về BLACK.
 */
Color GetBlockColor(int id) {
    auto colors = GetCellColors();
    if (id >= 0 && id < (int)colors.size()) {
        return colors[id];
    }
    return BLACK;
}
