#include "source2/Model/BlockService/BlockHistory.h"

void BlockHistory::Save(const std::shared_ptr<BlockMemento>& memento) {
    _undo_stack.push(memento);
    while (!_redo_stack.empty()) {
        _redo_stack.pop(); // Clear redo when new action occurs
    }
}

std::shared_ptr<BlockMemento> BlockHistory::Undo() {
    if (_undo_stack.empty()) return nullptr;
    auto state = _undo_stack.top();
    _undo_stack.pop();
    _redo_stack.push(state);
    return state;
}

std::shared_ptr<BlockMemento> BlockHistory::Redo() {
    if (_redo_stack.empty()) return nullptr;
    auto state = _redo_stack.top();
    _redo_stack.pop();
    _undo_stack.push(state);
    return state;
}

bool BlockHistory::CanUndo() const {
    return !_undo_stack.empty();
}

bool BlockHistory::CanRedo() const {
    return !_redo_stack.empty();
}

void BlockHistory::Clear() {
    while (!_undo_stack.empty()) {
        _undo_stack.pop();
    }
    
    while (!_redo_stack.empty()){
        _redo_stack.pop();
    } 
}
