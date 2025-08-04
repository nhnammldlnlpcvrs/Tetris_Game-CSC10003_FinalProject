#pragma once
#include <stack>
#include <memory>
#include "source2/Model/Block/BlockMemento.h"

class BlockHistory {
public:
    void Save(const std::shared_ptr<BlockMemento>& memento);
    std::shared_ptr<BlockMemento> Undo();
    std::shared_ptr<BlockMemento> Redo();

    bool CanUndo() const;
    bool CanRedo() const;
    void Clear();

private:
    std::stack<std::shared_ptr<BlockMemento>> _undo_stack;
    std::stack<std::shared_ptr<BlockMemento>> _redo_stack;
};
