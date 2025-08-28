#pragma once
#include "Model/Block/IMemento.h"

/**
 * @brief Lưu trạng thái xoay và vị trí của khối Block để hỗ trợ undo/redo.
 * 
 * Áp dụng trong Memento Pattern, lớp này đóng vai trò "Memento",
 * lưu giữ trạng thái (rotation, row, column) của một Block.
 */
class BlockMemento : public IMemento {
public:
    /**
     * @brief Constructor khởi tạo memento với trạng thái của khối.
     * @param rotationState Trạng thái xoay của khối.
     * @param rowOffset Vị trí offset theo hàng.
     * @param columnOffset Vị trí offset theo cột.
     */
    BlockMemento(int rotationState, int rowOffset, int columnOffset);

    /**
     * @brief Lấy trạng thái xoay được lưu.
     * @return int Trạng thái xoay.
     */
    int GetRotationState() const;

    /**
     * @brief Lấy offset theo hàng được lưu.
     * @return int Offset hàng.
     */
    int GetRowOffset() const;

    /**
     * @brief Lấy offset theo cột được lưu.
     * @return int Offset cột.
     */
    int GetColumnOffset() const;

private:
    /** @brief Trạng thái xoay của khối. */
    int m_rotationState;

    /** @brief Offset theo hàng (row) của khối. */
    int m_rowOffset;

    /** @brief Offset theo cột (column) của khối. */
    int m_columnOffset;
};
