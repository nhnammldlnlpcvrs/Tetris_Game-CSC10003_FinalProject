#pragma once

/**
 * @file colors.h
 * @brief Định nghĩa các màu sắc được sử dụng trong trò chơi và cung cấp hàm hỗ trợ.
 */

#include <raylib.h>
#include <vector>

/// Màu xám đậm - nền bảng hoặc khung chính.
extern const Color darkGrey;

/// Màu xanh lá cây - thường dùng cho các khối hoặc hiệu ứng tích cực.
extern const Color green;

/// Màu đỏ - thường dùng cho các cảnh báo hoặc lỗi.
extern const Color red;

/// Màu cam - một trong các màu khối.
extern const Color orange;

/// Màu vàng - một trong các màu khối.
extern const Color yellow;

/// Màu tím - một trong các màu khối.
extern const Color purple;

/// Màu cyan (xanh ngọc) - một trong các màu khối.
extern const Color cyan;

/// Màu xanh dương cơ bản - một trong các màu khối.
extern const Color blue;

/// Màu xanh dương nhạt - màu phụ trợ hoặc khối khác.
extern const Color lightBlue;

/// Màu xanh dương đậm - một trong các màu khối hoặc nền.
extern const Color darkBlue;

/**
 * @brief Trả về danh sách tất cả các màu khối dùng trong trò chơi.
 * 
 * @return std::vector<Color> Danh sách màu theo thứ tự định sẵn.
 */
std::vector<Color> GetCellColors();
