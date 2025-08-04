#pragma once

#include <memory>
#include "source2/Model/Block/Block.h"

/**
 * @brief Hiển thị khối block lên màn hình.
 * Tuân thủ MVC: Đây là View độc lập, không điều khiển logic.
 */
class BlockView {
public:
    void Render(Block& block, int offset_x, int offset_y) const;
};
