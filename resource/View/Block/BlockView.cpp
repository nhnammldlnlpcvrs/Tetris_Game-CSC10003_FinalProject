#include "BlockView.h"

void BlockView::Render(Block& block, int offset_x, int offset_y) const {
    block.Draw(offset_x, offset_y);
}
