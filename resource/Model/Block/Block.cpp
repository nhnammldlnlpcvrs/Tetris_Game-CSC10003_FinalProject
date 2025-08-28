#include "Block.h"

/**
 * @brief Constructor mặc định của Block.
 * Khởi tạo id, trạng thái xoay và vị trí offset bằng 0.
 */
Block::Block() : _id(0), _rotationState(0), _rowOffset(0), _columnOffset(0) {}

/**
 * @brief Lưu trạng thái hiện tại của khối (Memento Pattern).
 * @return std::shared_ptr<BlockMemento> đối tượng memento chứa thông tin trạng thái.
 */
std::shared_ptr<BlockMemento> Block::SaveState() const {
    return std::make_shared<BlockMemento>(_rotationState, _rowOffset, _columnOffset);
}

/**
 * @brief Khôi phục trạng thái khối từ memento.
 * @param memento Đối tượng BlockMemento đã lưu trạng thái trước đó.
 */
void Block::RestoreState(const std::shared_ptr<BlockMemento>& memento) {
    _rotationState = memento->GetRotationState();
    _rowOffset = memento->GetRowOffset();
    _columnOffset = memento->GetColumnOffset();
}

/**
 * @brief Vẽ khối tại vị trí hiện tại.
 * @param offset_x Tọa độ X offset trên màn hình.
 * @param offset_y Tọa độ Y offset trên màn hình.
 */
void Block::Draw(int offset_x, int offset_y) {
    auto positions = GetCellPositions();
    for (size_t i = 0; i < positions.size(); ++i) {
        DrawRectangle(
            offset_x + positions[i].column * cellSize,
            offset_y + positions[i].row * cellSize,
            cellSize - 1, cellSize - 1,
            _colors[i % _colors.size()]
        );
    }
}

/**
 * @brief Vẽ bản xem trước (preview) của khối, dịch khối về góc trên bên trái.
 * @param offset_x Tọa độ X offset.
 * @param offset_y Tọa độ Y offset.
 */
void Block::DrawPreview(int offset_x, int offset_y) {
    auto positions = GetCellPositions();

    int minRow = INT_MAX, minCol = INT_MAX;
    for (const auto& pos : positions) {
        if (pos.row < minRow) minRow = pos.row;
        if (pos.column < minCol) minCol = pos.column;
    }

    for (size_t i = 0; i < positions.size(); ++i) {
        DrawRectangle(
            offset_x + (positions[i].column - minCol) * cellSize,
            offset_y + (positions[i].row - minRow) * cellSize,
            cellSize - 1, cellSize - 1,
            _colors[i % _colors.size()]
        );
    }
}

/**
 * @brief Di chuyển khối theo số hàng và cột chỉ định.
 * @param rows Số hàng dịch chuyển.
 * @param columns Số cột dịch chuyển.
 */
void Block::Move(int rows, int columns) {
    _rowOffset += rows;
    _columnOffset += columns;
}

/** @brief Di chuyển khối sang trái một ô. */
void Block::MoveLeft() { _columnOffset--; }

/** @brief Di chuyển khối sang phải một ô. */
void Block::MoveRight() { _columnOffset++; }

/** @brief Di chuyển khối xuống dưới một ô. */
void Block::MoveDown() { _rowOffset++; }

/** @brief Di chuyển khối lên trên một ô. */
void Block::MoveUp() { _rowOffset--; }

/** @brief Xoay khối theo chiều kim đồng hồ. */
void Block::Rotate() { _rotationState = (_rotationState + 1) % 4; }

/** @brief Xoay khối ngược chiều kim đồng hồ. */
void Block::RotateBack() { _rotationState = (_rotationState + 3) % 4; }

/**
 * @brief Lấy vị trí của các ô (cell) mà khối chiếm.
 * @return std::vector<Position> danh sách tọa độ các ô.
 */
std::vector<Position> Block::GetCellPositions() const {
    std::vector<Position> positions;
    for (const auto& pos : _cells.at(_rotationState)) {
        positions.push_back(Position{ _rowOffset + pos.row, _columnOffset + pos.column });
    }
    return positions;
}

/**
 * @brief Lấy kích thước khối theo offset hiện tại.
 * @return std::pair<int,int> {rowOffset, columnOffset}.
 */
std::pair<int, int> Block::GetSize() const {
    return { _rowOffset, _columnOffset };
}

/**
 * @brief Lấy ID của khối.
 * @return int ID khối.
 */
int Block::GetId() const {
    return _id;
}

// /**
//  * @brief Lấy màu của các ô trong khối.
//  * @return std::vector<Color> danh sách màu.
//  */
// std::vector<Color> Block::GetCellColor() const {
//     return _colors;
// }
