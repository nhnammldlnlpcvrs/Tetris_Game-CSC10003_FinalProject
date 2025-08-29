#pragma once
#include <stack>
#include <memory>
#include "Model/Block/BlockMemento.h"

/**
 * @class BlockHistory
 * @brief Quản lý lịch sử trạng thái của Block theo mô hình Undo/Redo.
 *
 * Lớp này lưu trữ các trạng thái (Memento) của Block trong 2 stack:
 * - `_undo_stack`: chứa các trạng thái có thể Undo.
 * - `_redo_stack`: chứa các trạng thái có thể Redo.
 *
 * Mỗi khi lưu trạng thái mới, stack Redo sẽ được xóa để đảm bảo tính đúng đắn.
 */
class BlockHistory {
public:
    /**
     * @brief Lưu trạng thái hiện tại vào stack Undo.
     * 
     * Khi lưu trạng thái mới, stack Redo sẽ bị xóa vì không còn hợp lệ nữa.
     * 
     * @param memento Trạng thái cần lưu (được bọc trong shared_ptr).
     */
    void Save(const std::shared_ptr<BlockMemento>& memento);

    /**
     * @brief Hoàn tác (Undo) để quay về trạng thái trước đó.
     * 
     * Trạng thái hiện tại sẽ được chuyển sang stack Redo.
     * 
     * @return std::shared_ptr<BlockMemento> Trạng thái trước đó hoặc nullptr nếu không thể Undo.
     */
    std::shared_ptr<BlockMemento> Undo();

    /**
     * @brief Làm lại (Redo) trạng thái vừa Undo.
     * 
     * Trạng thái từ stack Redo sẽ được đưa ngược lại vào stack Undo.
     * 
     * @return std::shared_ptr<BlockMemento> Trạng thái tiếp theo hoặc nullptr nếu không thể Redo.
     */
    std::shared_ptr<BlockMemento> Redo();

    /**
     * @brief Kiểm tra có thể Undo hay không.
     * @return true nếu có thể Undo, false nếu không.
     */
    bool CanUndo() const;

    /**
     * @brief Kiểm tra có thể Redo hay không.
     * @return true nếu có thể Redo, false nếu không.
     */
    bool CanRedo() const;

    /**
     * @brief Xóa toàn bộ lịch sử Undo/Redo.
     */
    void Clear();

private:
    std::stack<std::shared_ptr<BlockMemento>> _undo_stack; ///< Stack lưu trạng thái Undo.
    std::stack<std::shared_ptr<BlockMemento>> _redo_stack; ///< Stack lưu trạng thái Redo.
};
