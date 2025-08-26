#include "BlockMemento.h"

BlockMemento ::BlockMemento (int rotationState, int rowOffset, int columnOffset){
    m_rotationState = rotationState;
    m_rowOffset = rowOffset;
    m_columnOffset = columnOffset;
}

int BlockMemento::GetRotationState() const {
    return m_rotationState;
}

int BlockMemento::GetRowOffset() const {
    return m_rowOffset;
}

int BlockMemento::GetColumnOffset() const {
    return m_columnOffset;
}
