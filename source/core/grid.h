#pragma once
#include <vector>
#include <raylib.h>

/**
 * @class Grid
 * @brief Đại diện cho lưới chơi Tetris kích thước 20x10.
 *
 * Lớp này quản lý dữ liệu ô trong lưới, kiểm tra va chạm, xử lý xóa dòng và vẽ lưới.
 */
class Grid
{
public:
    /**
     * @brief Constructor mặc định, khởi tạo thông số cơ bản.
     */
    Grid();

    /**
     * @brief Thiết lập lại lưới, gán tất cả ô về trạng thái rỗng.
     */
    void Initialize();

    /**
     * @brief In trạng thái lưới ra console (debug).
     */
    void Print();

    /**
     * @brief Vẽ lưới lên màn hình sử dụng Raylib.
     */
    void Draw();

    /**
     * @brief Kiểm tra xem ô có nằm ngoài biên của lưới không.
     * @param row Hàng (0-based).
     * @param column Cột (0-based).
     * @return True nếu nằm ngoài lưới.
     */
    bool IsCellOutside(int row, int column);

    /**
     * @brief Kiểm tra xem ô có rỗng (chưa có khối) không.
     * @param row Hàng (0-based).
     * @param column Cột (0-based).
     * @return True nếu ô trống.
     */
    bool IsCellEmpty(int row, int column);

    /**
     * @brief Xóa các dòng đầy đủ trong lưới.
     * @return Số dòng đã xóa.
     */
    int ClearFullRows();

    /**
     * @brief Ma trận chính chứa trạng thái các ô.
     * 0 là ô trống, các số khác đại diện cho màu hoặc khối.
     */
    int grid[20][10];

private:
    /**
     * @brief Kiểm tra một dòng có đầy đủ khối hay không.
     * @param row Chỉ số dòng.
     * @return True nếu dòng đầy.
     */
    bool IsRowFull(int row);

    /**
     * @brief Xóa toàn bộ khối trong dòng chỉ định.
     * @param row Dòng cần xóa.
     */
    void ClearRow(int row);

    /**
     * @brief Di chuyển dòng xuống dưới một số lượng dòng nhất định.
     * @param row Dòng bắt đầu.
     * @param numRows Số dòng cần dịch xuống.
     */
    void MoveRowDown(int row, int numRows);

    /**
     * @brief Tổng số dòng của lưới.
     */
    int numRows;

    /**
     * @brief Tổng số cột của lưới.
     */
    int numCols;

    /**
     * @brief Kích thước của một ô vuông (pixel).
     */
    int cellSize;

    /**
     * @brief Danh sách màu tương ứng với các số trong lưới.
     */
    std::vector<Color> colors;
};
