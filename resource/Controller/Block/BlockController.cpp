#include "BlockController.h"

BlockController::BlockController(std::shared_ptr<Block> block)
    : block_(std::move(block)) {
    if (!block_) {
        throw std::invalid_argument("BlockController: nullptr block passed.");
    }
}

void BlockController::Move(int delta_row, int delta_col) {
    SaveState();
    block_->Move(delta_row, delta_col);
}

void BlockController::Rotate() {
    SaveState();
    block_->Rotate();
}

std::shared_ptr<Block> BlockController::GetBlock() const {
    return block_;
}

void BlockController::SaveState() {
    _history.Save(block_->SaveState());
}

void BlockController::Undo() {
    if (_history.CanUndo()) {
        auto memento = _history.Undo();
        if (memento) {
            block_->RestoreState(memento);
        }
    }
}

void BlockController::Redo() {
    if (_history.CanRedo()) {
        auto memento = _history.Redo();
        if (memento) {
            block_->RestoreState(memento);
        }
    }
}
