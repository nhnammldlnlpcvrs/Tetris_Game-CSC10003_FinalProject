#include "Grid.h"

/**
 * @brief Khởi tạo lưới game với kích thước rows × columns.
 *
 * Tất cả ô trong lưới ban đầu đều là màu trong suốt (alpha = 0).
 *
 * @param rows Số hàng của lưới.
 * @param columns Số cột của lưới.
 */
Grid::Grid(int rows, int columns)
    : _rows(rows), _columns(columns),
      _cells(rows, std::vector<Color>(columns, Color{0, 0, 0, 0})) {}

/**
 * @brief Kiểm tra ô có bị chiếm không.
 *
 * @param row Chỉ số hàng.
 * @param column Chỉ số cột.
 * @return true Nếu ô ngoài lưới hoặc có màu (alpha ≠ 0).
 * @return false Nếu ô còn trống.
 */
bool Grid::IsCellOccupied(int row, int column) const {
    if (row < 0 || row >= _rows || column < 0 || column >= _columns)
        return true; // ngoài lưới xem như occupied
    return _cells[row][column].a != 0;
}

/**
 * @brief Gán màu cho một ô trong lưới.
 *
 * @param row Chỉ số hàng.
 * @param column Chỉ số cột.
 * @param color Màu muốn gán.
 */
void Grid::SetCell(int row, int column, const Color& color) {
    if (row < 0 || row >= _rows || column < 0 || column >= _columns)
        return; // tránh ghi ngoài lưới
    _cells[row][column] = color;
}

/**
 * @brief Xóa (làm trống) một ô trong lưới.
 *
 * @param row Chỉ số hàng.
 * @param column Chỉ số cột.
 */
void Grid::ClearCell(int row, int column) {
    if (row < 0 || row >= _rows || column < 0 || column >= _columns)
        return;
    _cells[row][column] = Color{0, 0, 0, 0};
}

/**
 * @brief Xóa các dòng đầy trong lưới.
 *
 * Nếu một dòng đầy (không có ô trống), dòng đó bị xóa và các dòng trên được đẩy xuống.
 * Một dòng trống mới được chèn ở trên cùng.
 *
 * @return int Số dòng đã xóa.
 */
int Grid::ClearFullLines() {
    int cleared = 0;

    for (int row = _rows - 1; row >= 0; --row) {
        bool full = std::all_of(_cells[row].begin(), _cells[row].end(),
                                [](const Color& c) { return c.a != 0; });

        if (full) {
            // Xóa dòng đầy
            _cells.erase(_cells.begin() + row);

            // Thêm dòng trống ở trên cùng
            _cells.insert(_cells.begin(), std::vector<Color>(_columns, Color{0, 0, 0, 0}));

            ++cleared;
            ++row; // kiểm tra lại dòng vừa đẩy xuống
        }
    }

    return cleared;
}

/**
 * @brief Lấy số hàng của lưới.
 * @return int Số hàng.
 */
int Grid::GetRows() const {
    return _rows;
}

/**
 * @brief Lấy số cột của lưới.
 * @return int Số cột.
 */
int Grid::GetColumns() const {
    return _columns;
}

/**
 * @brief Lấy toàn bộ dữ liệu ô trong lưới.
 *
 * @return const std::vector<std::vector<Color>>& Ma trận màu (tham chiếu hằng).
 */
const std::vector<std::vector<Color>>& Grid::GetCells() const {
    return _cells;
}

/**
 * @brief Kiểm tra vị trí tập hợp các ô có hợp lệ không.
 *
 * Hợp lệ nếu toàn bộ tọa độ đều nằm trong lưới và không đè lên ô đã chiếm.
 *
 * @param positions Danh sách tọa độ cần kiểm tra.
 * @return true Nếu vị trí hợp lệ.
 * @return false Nếu vị trí không hợp lệ.
 */
bool Grid::IsValidPosition(const std::vector<Position>& positions) const {
    for (const auto& pos : positions) {
        if (pos.row < 0 || pos.row >= _rows || pos.column < 0 || pos.column >= _columns)
            return false;
        if (IsCellOccupied(pos.row, pos.column))
            return false;
    }
    return true;
}

/**
 * @brief Kiểm tra xem có block nào chạm đỉnh lưới không.
 *
 * @return true Nếu có ô ở hàng 0 đã bị chiếm.
 * @return false Nếu chưa có ô nào ở hàng 0.
 */
bool Grid::HasBlockAtTop() const {
    for (int col = 0; col < _columns; ++col) {
        if (_cells[0][col].a != 0) return true;
    }
    return false;
}
