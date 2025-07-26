#pragma once
#include <vector>
#include <map>
#include "../core/position.h"
#include "colors.h"

/**
 * @class Block
 * @brief Đại diện cho một khối trong trò chơi Tetris, bao gồm các ô (cells), vị trí, và trạng thái xoay.
 */
class Block
{
public:
    /**
     * @brief Constructor khởi tạo block với ID ngẫu nhiên và trạng thái xoay ban đầu.
     */
    Block();

    /**
     * @brief Vẽ block lên màn hình tại vị trí được chỉ định.
     * @param offsetX Vị trí ngang của block trên màn hình (theo pixel).
     * @param offsetY Vị trí dọc của block trên màn hình (theo pixel).
     */
    void Draw(int offsetX, int offsetY);

    /**
     * @brief Di chuyển block một số hàng và cột nhất định.
     * @param rows Số hàng cần di chuyển.
     * @param columns Số cột cần di chuyển.
     */
    void Move(int rows, int columns);

    /**
     * @brief Trả về danh sách vị trí các ô hiện tại của block.
     * @return Vector các Position của các ô trong block.
     */
    std::vector<Position> GetCellPositions();

    /**
     * @brief Xoay block theo chiều kim đồng hồ.
     */
    void Rotate();

    /**
     * @brief Hoàn tác lần xoay gần nhất (xoay ngược lại).
     */
    void UndoRotation();

    /**
     * @brief ID đại diện cho loại block (0-6).
     */
    int id;

    /**
     * @brief Bản đồ lưu trạng thái các ô của block tương ứng với từng trạng thái xoay (0-3).
     */
    std::map<int, std::vector<Position>> cells;

    /**
     * @brief Lấy kích thước của block (chiều ngang và dọc).
     * @return Cặp giá trị {số hàng, số cột}.
     */
    std::pair<int, int> GetSize();

private:
    int cellSize;              ///< Kích thước mỗi ô (cell) trong block.
    int rotationState;         ///< Trạng thái xoay hiện tại (0-3).
    std::vector<Color> colors; ///< Danh sách màu của block.
    int rowOffset;             ///< Vị trí hàng hiện tại của block.
    int columnOffset;          ///< Vị trí cột hiện tại của block.
};
