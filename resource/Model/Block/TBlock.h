#pragma once
#include "Model/Block/Block.h"

/**
 * @class TBlock
 * @brief Đại diện cho khối T trong trò chơi Tetris.
 *
 * Khối T có bốn trạng thái xoay khác nhau, với tâm xoay ở vị trí trung tâm.
 * Mỗi khối được xác định bởi màu sắc và tọa độ các ô trong ma trận.
 */
class TBlock : public Block {
public:
    /**
     * @brief Khởi tạo khối T với trạng thái mặc định.
     */
    TBlock();
    
    /**
     * @brief Lấy màu của các ô trong khối T ở trạng thái xoay hiện tại.
     * @return std::vector<Color> Danh sách màu của các ô.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao (clone) của khối T.
     * @return std::unique_ptr<Block> Con trỏ thông minh tới bản sao của khối.
     */
    std::unique_ptr<Block> Clone() const override;
};
