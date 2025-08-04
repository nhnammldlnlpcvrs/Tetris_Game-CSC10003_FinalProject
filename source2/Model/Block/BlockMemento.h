#pragma once
#include "../source2/Model//Block/IMemento.h"

/**
 * @brief Lưu trạng thái xoay và vị trí của khối Block để hỗ trợ undo,redo.
 */
class BlockMemento : public IMemento {
public:
    BlockMemento(int rotationState, int rowOffset, int columnOffset);

    int GetRotationState() const;
    int GetRowOffset() const;
    int GetColumnOffset() const;

private:
    int m_rotationState;
    int m_rowOffset;
    int m_columnOffset;
};
