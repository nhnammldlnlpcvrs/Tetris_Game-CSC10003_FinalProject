#pragma once

#include "raylib.h"
#include <vector>

/**
 * @file colors.h
 * @brief Khai báo các màu sắc được sử dụng trong trò chơi Tetris và cung cấp hàm hỗ trợ.
 */

/**
 * @brief Màu xám đậm - nền bảng hoặc khung chính.
 */
extern const Color darkGrey;

/**
 * @brief Màu xanh lá cây - thường dùng cho khối S.
 */
extern const Color green;

/**
 * @brief Màu đỏ - thường dùng cho khối Z hoặc cảnh báo.
 */
extern const Color red;

/**
 * @brief Màu cam - thường dùng cho khối L.
 */
extern const Color orange;

/**
 * @brief Màu vàng - thường dùng cho khối O.
 */
extern const Color yellow;

/**
 * @brief Màu tím - thường dùng cho khối T.
 */
extern const Color purple;

/**
 * @brief Màu cyan (xanh ngọc) - thường dùng cho khối I.
 */
extern const Color cyan;

/**
 * @brief Màu xanh dương cơ bản - thường dùng cho khối J.
 */
extern const Color blue;

/**
 * @brief Màu xanh dương nhạt - màu phụ trợ (không nằm trong 7 khối chuẩn).
 */
extern const Color lightBlue;

/**
 * @brief Màu xanh dương đậm - có thể dùng cho nền hoặc hiệu ứng phụ.
 */
extern const Color darkBlue;

/**
 * @brief Trả về danh sách tất cả các màu khối dùng trong trò chơi.
 * 
 * Thứ tự mặc định:
 * - 0: darkGrey (nền)
 * - 1: cyan (I)
 * - 2: blue (J)
 * - 3: orange (L)
 * - 4: yellow (O)
 * - 5: green (S)
 * - 6: purple (T)
 * - 7: red (Z)
 *
 * @return std::vector<Color> Danh sách màu theo thứ tự định sẵn.
 */
std::vector<Color> GetCellColors();

/**
 * @brief Lấy màu của block dựa trên ID.
 *
 * @param id ID của block (0 = nền, 1-7 = các khối chuẩn).
 * @return Color Màu sắc tương ứng, hoặc BLACK nếu id không hợp lệ.
 */
inline Color GetBlockColor(int id);
