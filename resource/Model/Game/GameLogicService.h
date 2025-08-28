#pragma once

#include "Model/Block/Block.h"
#include "Core/Grid/Grid.h"
#include "Core/Graphics/Color.h"

/**
 * @class GameLogicService
 * @brief Cung cấp các hàm xử lý logic chính cho trò chơi Tetris.
 *
 * Lớp này quản lý việc di chuyển, xoay, khóa block vào grid,
 * kiểm tra xóa dòng, và xác định trạng thái game over.
 */
class GameLogicService {
public:
    /**
     * @brief Di chuyển block sang trái.
     * @param block Block cần di chuyển.
     * @param grid Lưới để kiểm tra va chạm.
     * @return true nếu di chuyển thành công, false nếu bị cản.
     */
    bool MoveLeft(Block& block, const Grid& grid) const;

    /**
     * @brief Di chuyển block sang phải.
     * @param block Block cần di chuyển.
     * @param grid Lưới để kiểm tra va chạm.
     * @return true nếu di chuyển thành công, false nếu bị cản.
     */
    bool MoveRight(Block& block, const Grid& grid) const;

    /**
     * @brief Di chuyển block xuống dưới.
     * @param block Block cần di chuyển.
     * @param grid Lưới để kiểm tra va chạm.
     * @return true nếu di chuyển thành công, false nếu bị cản.
     */
    bool MoveDown(Block& block, const Grid& grid) const;

    /**
     * @brief Xoay block (theo chiều kim đồng hồ).
     * @param block Block cần xoay.
     * @param grid Lưới để kiểm tra va chạm.
     * @return true nếu xoay thành công, false nếu bị cản.
     */
    bool Rotate(Block& block, const Grid& grid) const;

    /**
     * @brief Khóa block vào grid khi block chạm đáy hoặc bị cản.
     * @param grid Lưới để cập nhật trạng thái.
     * @param block Block cần được khóa.
     */
    void LockBlock(Grid& grid, const Block& block) const;

    /**
     * @brief Xóa các dòng đầy đủ trong grid.
     * @param grid Lưới cần kiểm tra.
     * @return Số dòng đã xóa.
     */
    int ClearLines(Grid& grid) const;

    /**
     * @brief Kiểm tra game có kết thúc hay chưa.
     * @param grid Lưới để kiểm tra.
     * @return true nếu game over, false nếu vẫn chơi tiếp.
     */
    bool IsGameOver(const Grid& grid) const;
};
