#pragma once
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <memory>
#include "raylib.h"
#include "Core/Position/Position.h"
#include "Core/Graphics/Color.h"
#include "BlockMemento.h"

/**
 * @brief Lớp đại diện cho một khối trong trò chơi (Tetris Block).
 * 
 * Lớp này quản lý vị trí, trạng thái xoay, màu sắc và khả năng vẽ khối.
 * Đồng thời hỗ trợ lưu/khôi phục trạng thái theo Memento Pattern.
 */
class Block {
public:
    /**
     * @brief Constructor mặc định, khởi tạo khối rỗng.
     */
    Block();

    /**
     * @brief Lưu trạng thái hiện tại của khối.
     * @return std::shared_ptr<BlockMemento> đối tượng memento chứa trạng thái.
     */
    std::shared_ptr<BlockMemento> SaveState() const;

    /**
     * @brief Khôi phục trạng thái khối từ memento.
     * @param memento Đối tượng BlockMemento chứa trạng thái trước đó.
     */
    void RestoreState(const std::shared_ptr<BlockMemento>& memento);

    /**
     * @brief Vẽ khối tại vị trí hiện tại.
     * @param offset_x Tọa độ X offset trên màn hình.
     * @param offset_y Tọa độ Y offset trên màn hình.
     */
    void Draw(int offset_x, int offset_y);

    /**
     * @brief Vẽ bản xem trước của khối, dịch về góc trái trên.
     * @param offset_x Tọa độ X offset.
     * @param offset_y Tọa độ Y offset.
     */
    void DrawPreview(int offset_x, int offset_y);

    /**
     * @brief Di chuyển khối theo số hàng và cột chỉ định.
     * @param rows Số hàng dịch chuyển.
     * @param columns Số cột dịch chuyển.
     */
    void Move(int rows, int columns);

    /** @brief Di chuyển khối sang trái một ô. */
    void MoveLeft();

    /** @brief Di chuyển khối sang phải một ô. */
    void MoveRight();

    /** @brief Di chuyển khối xuống dưới một ô. */
    void MoveDown();

    /** @brief Di chuyển khối lên trên một ô. */
    void MoveUp();

    /** @brief Xoay khối theo chiều kim đồng hồ. */
    void Rotate();

    /** @brief Xoay khối ngược chiều kim đồng hồ. */
    void RotateBack();

    /**
     * @brief Lấy danh sách vị trí các ô trong khối.
     * @return std::vector<Position> Danh sách tọa độ các ô.
     */
    std::vector<Position> GetCellPositions() const;

    /**
     * @brief Lấy kích thước khối theo offset.
     * @return std::pair<int,int> {rowOffset, columnOffset}.
     */
    std::pair<int, int> GetSize() const;

    /**
     * @brief Lấy ID khối.
     * @return int ID khối.
     */
    int GetId() const;

    /**
     * @brief Lấy danh sách màu của các ô trong khối.
     * (Phương thức thuần ảo, mỗi loại khối định nghĩa riêng).
     * @return std::vector<Color> Danh sách màu.
     */
    virtual std::vector<Color> GetCellColor() const = 0;

    /**
     * @brief Tạo bản sao của khối (clone).
     * (Phương thức thuần ảo, mỗi loại khối định nghĩa riêng).
     * @return std::unique_ptr<Block> bản sao của khối.
     */
    virtual std::unique_ptr<Block> Clone() const = 0;

    /**
     * @brief Destructor ảo.
     */
    virtual ~Block() = default;

protected:
    /** @brief Kích thước một ô (pixel). */
    static constexpr int cellSize = 30;

    /** @brief ID của khối. */
    int _id;

    /** @brief Trạng thái xoay hiện tại (0–3). */
    int _rotationState;

    /** @brief Offset theo hàng (row). */
    int _rowOffset;

    /** @brief Offset theo cột (column). */
    int _columnOffset;

    /** @brief Map trạng thái xoay → danh sách vị trí các ô. */
    std::map<int, std::vector<Position>> _cells;

    /** @brief Danh sách màu của khối. */
    std::vector<Color> _colors;
};
