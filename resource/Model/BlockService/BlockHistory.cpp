#include "BlockHistory.h"

/**
 * @brief Lưu trạng thái hiện tại vào stack Undo, đồng thời xóa stack Redo.
 */
void BlockHistory::Save(const std::shared_ptr<BlockMemento>& memento) {
    _undo_stack.push(memento);
    while (!_redo_stack.empty()) {
        _redo_stack.pop(); // Clear redo when new action occurs
    }
}

/**
 * @brief Hoàn tác (Undo) về trạng thái trước đó.
 * 
 * @return std::shared_ptr<BlockMemento> Trạng thái trước đó hoặc nullptr nếu không thể Undo.
 */
std::shared_ptr<BlockMemento> BlockHistory::Undo() {
    if (_undo_stack.empty()) return nullptr;
    auto state = _undo_stack.top();
    _undo_stack.pop();
    _redo_stack.push(state);
    return state;
}

/**
 * @brief Làm lại (Redo) trạng thái vừa Undo.
 * 
 * @return std::shared_ptr<BlockMemento> Trạng thái tiếp theo hoặc nullptr nếu không thể Redo.
 */
std::shared_ptr<BlockMemento> BlockHistory::Redo() {
    if (_redo_stack.empty()) return nullptr;
    auto state = _redo_stack.top();
    _redo_stack.pop();
    _undo_stack.push(state);
    return state;
}

/**
 * @brief Kiểm tra có thể Undo hay không.
 */
bool BlockHistory::CanUndo() const {
    return !_undo_stack.empty();
}

/**
 * @brief Kiểm tra có thể Redo hay không.
 */
bool BlockHistory::CanRedo() const {
    return !_redo_stack.empty();
}

/**
 * @brief Xóa toàn bộ lịch sử Undo/Redo.
 */
void BlockHistory::Clear() {
    while (!_undo_stack.empty()) {
        _undo_stack.pop();
    }
    
    while (!_redo_stack.empty()){
        _redo_stack.pop();
    } 
}
