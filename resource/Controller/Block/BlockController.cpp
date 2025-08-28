#include "BlockController.h"

/**
 * @brief Khởi tạo BlockController với một block cụ thể.
 * @param block Con trỏ thông minh tới đối tượng Block cần quản lý.
 * @throws std::invalid_argument nếu block là nullptr.
 */
BlockController::BlockController(std::shared_ptr<Block> block)
    : block_(std::move(block)) {
    if (!block_) {
        throw std::invalid_argument("BlockController: nullptr block passed.");
    }
}

/**
 * @brief Di chuyển block theo hàng và cột.
 * @param delta_row Số hàng cần dịch chuyển.
 * @param delta_col Số cột cần dịch chuyển.
 */
void BlockController::Move(int delta_row, int delta_col) {
    SaveState();
    block_->Move(delta_row, delta_col);
}

/**
 * @brief Xoay block sang trạng thái tiếp theo.
 */
void BlockController::Rotate() {
    SaveState();
    block_->Rotate();
}

/**
 * @brief Lấy block hiện tại.
 * @return Con trỏ thông minh tới block được quản lý.
 */
std::shared_ptr<Block> BlockController::GetBlock() const {
    return block_;
}

/**
 * @brief Lưu trạng thái hiện tại của block vào lịch sử.
 */
void BlockController::SaveState() {
    _history.Save(block_->SaveState());
}

/**
 * @brief Hoàn tác (undo) hành động gần nhất trên block.
 */
void BlockController::Undo() {
    if (_history.CanUndo()) {
        auto memento = _history.Undo();
        if (memento) {
            block_->RestoreState(memento);
        }
    }
}

/**
 * @brief Làm lại (redo) hành động đã hoàn tác trước đó.
 */
void BlockController::Redo() {
    if (_history.CanRedo()) {
        auto memento = _history.Redo();
        if (memento) {
            block_->RestoreState(memento);
        }
    }
}
