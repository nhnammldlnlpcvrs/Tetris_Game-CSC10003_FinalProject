#pragma once

/**
 * @brief Interface cơ sở cho Memento trong Memento Pattern.
 * 
 * Lớp này đóng vai trò "Memento" trừu tượng, cho phép lưu trữ trạng thái
 * của các đối tượng khác (ví dụ: BlockMemento trong Tetris).
 * 
 * Các lớp kế thừa (như BlockMemento) sẽ định nghĩa cụ thể trạng thái cần lưu.
 */
class IMemento {
public:
    /**
     * @brief Destructor ảo mặc định.
     */
    virtual ~IMemento() = default;
};
