#include "BlockMemento.h"

/**
 * @brief Constructor của BlockMemento.
 * @param rotationState Trạng thái xoay của khối.
 * @param rowOffset Vị trí offset theo hàng.
 * @param columnOffset Vị trí offset theo cột.
 */
BlockMemento::BlockMemento(int rotationState, int rowOffset, int columnOffset) {
    m_rotationState = rotationState;
    m_rowOffset = rowOffset;
    m_columnOffset = columnOffset;
}

/**
 * @brief Lấy trạng thái xoay của khối.
 * @return int Trạng thái xoay.
 */
int BlockMemento::GetRotationState() const {
    return m_rotationState;
}

/**
 * @brief Lấy offset theo hàng.
 * @return int Offset hàng.
 */
int BlockMemento::GetRowOffset() const {
    return m_rowOffset;
}

/**
 * @brief Lấy offset theo cột.
 * @return int Offset cột.
 */
int BlockMemento::GetColumnOffset() const {
    return m_columnOffset;
}
