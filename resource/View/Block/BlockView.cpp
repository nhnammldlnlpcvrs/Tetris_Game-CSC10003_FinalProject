#include "BlockView.h"

/**
 * @brief Vẽ một khối tại vị trí được chỉ định.
 *
 * Hàm này gọi phương thức Draw() của đối tượng Block để hiển thị khối.
 *
 * @param block Khối cần được vẽ.
 * @param offset_x Tọa độ dịch chuyển theo trục X.
 * @param offset_y Tọa độ dịch chuyển theo trục Y.
 */
void BlockView::Render(Block& block, int offset_x, int offset_y) const {
    block.Draw(offset_x, offset_y);
}
