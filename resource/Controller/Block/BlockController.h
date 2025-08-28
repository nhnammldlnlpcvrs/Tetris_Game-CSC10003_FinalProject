#pragma once

#include <memory>
#include <stdexcept>
#include "View/Block/BlockView.h"
#include "Model/BlockService/BlockHistory.h"
#include "Model/Block/Block.h"

/**
 * @class BlockController
 * @brief Quản lý và điều khiển hành vi của một Block trong trò chơi.
 *
 * BlockController chịu trách nhiệm di chuyển, xoay khối và quản lý undo/redo 
 * thông qua việc lưu lại lịch sử trạng thái (Memento Pattern). 
 * Ngoài ra, nó áp dụng Command Pattern để thực hiện và đảo ngược các hành động.
 */
class BlockController {
public:
    /**
     * @brief Khởi tạo một BlockController cho Block được chỉ định.
     * @param block Con trỏ thông minh trỏ đến đối tượng Block cần điều khiển.
     */
    explicit BlockController(std::shared_ptr<Block> block);

    /**
     * @brief Di chuyển Block theo hàng và cột.
     * @param delta_row Số hàng cần di chuyển (âm nếu lên trên, dương nếu xuống).
     * @param delta_col Số cột cần di chuyển (âm nếu sang trái, dương nếu sang phải).
     */
    void Move(int delta_row, int delta_col);

    /**
     * @brief Xoay Block sang trạng thái kế tiếp.
     */
    void Rotate();

    /**
     * @brief Lấy đối tượng Block hiện tại.
     * @return Con trỏ thông minh tới Block.
     */
    std::shared_ptr<Block> GetBlock() const;

    /**
     * @brief Lưu trạng thái hiện tại của Block vào lịch sử.
     */
    void SaveState();

    /**
     * @brief Hoàn tác hành động cuối cùng (Undo).
     * @throw std::runtime_error Nếu không còn trạng thái trước đó.
     */
    void Undo();

    /**
     * @brief Làm lại hành động đã hoàn tác (Redo).
     * @throw std::runtime_error Nếu không còn trạng thái để redo.
     */
    void Redo();

private:
    /**
     * @brief Con trỏ đến Block đang được điều khiển.
     */
    std::shared_ptr<Block> block_;

    /**
     * @brief Quản lý lịch sử trạng thái của Block (undo/redo).
     */
    BlockHistory _history;
};
