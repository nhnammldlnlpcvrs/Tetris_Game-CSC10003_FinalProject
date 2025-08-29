#pragma once
#include "Model/Block/Block.h"

/**
 * @class ZBlock
 * @brief Đại diện cho khối Z trong trò chơi Tetris.
 *
 * Khối Z có 4 trạng thái xoay khác nhau. Mỗi trạng thái được mô tả
 * bởi tập hợp các tọa độ ô trong ma trận. Mặc định khối có màu đỏ.
 */
class ZBlock : public Block {
public:
    /**
     * @brief Khởi tạo khối Z với trạng thái mặc định.
     */
    ZBlock();

    /**
     * @brief Lấy màu của các ô trong khối Z ở trạng thái xoay hiện tại.
     * 
     * Nếu khối chỉ có một màu thì toàn bộ ô sẽ cùng màu.
     * Nếu có nhiều màu, trả về danh sách màu tương ứng với từng ô.
     *
     * @return std::vector<Color> Danh sách màu của các ô.
     */
    std::vector<Color> GetCellColor() const override;

    /**
     * @brief Tạo một bản sao của khối Z.
     *
     * @return std::unique_ptr<Block> Con trỏ thông minh tới bản sao khối.
     */
    std::unique_ptr<Block> Clone() const override;
};
