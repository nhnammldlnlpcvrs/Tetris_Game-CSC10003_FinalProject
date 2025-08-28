#pragma once

#include <memory>
#include "Model/Block/Block.h"

/**
 * @class BlockView
 * @brief Lớp chịu trách nhiệm hiển thị một Block lên màn hình.
 *
 * Theo mô hình MVC, đây là thành phần View:
 * - Không quản lý logic trò chơi.
 * - Chỉ đảm nhận việc hiển thị khối (Block).
 */
class BlockView {
public:
    /**
     * @brief Vẽ một khối tại vị trí chỉ định.
     * 
     * @param block Khối cần hiển thị.
     * @param offset_x Tọa độ dịch chuyển theo trục X.
     * @param offset_y Tọa độ dịch chuyển theo trục Y.
     */
    void Render(Block& block, int offset_x, int offset_y) const;
};
