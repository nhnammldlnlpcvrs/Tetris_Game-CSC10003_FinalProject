#include "GameLogicService.h"

/**
 * @brief Di chuyển block sang trái nếu có thể.
 * 
 * @param block Khối Tetris cần di chuyển.
 * @param grid Lưới trò chơi dùng để kiểm tra va chạm.
 * @return true Nếu di chuyển thành công.
 * @return false Nếu không thể di chuyển (block sẽ trở lại vị trí cũ).
 */
bool GameLogicService::MoveLeft(Block& block, const Grid& grid) const {
    block.MoveLeft();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveRight();
        return false;
    }
    return true;
}

/**
 * @brief Di chuyển block sang phải nếu có thể.
 *
 * @param block Khối Tetris cần di chuyển.
 * @param grid Lưới trò chơi dùng để kiểm tra va chạm.
 * @return true Nếu di chuyển thành công.
 * @return false Nếu không thể di chuyển (block sẽ trở lại vị trí cũ).
 */
bool GameLogicService::MoveRight(Block& block, const Grid& grid) const {
    block.MoveRight();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveLeft();
        return false;
    }
    return true;
}

/**
 * @brief Di chuyển block xuống một hàng nếu có thể.
 *
 * @param block Khối Tetris cần di chuyển.
 * @param grid Lưới trò chơi dùng để kiểm tra va chạm.
 * @return true Nếu di chuyển thành công.
 * @return false Nếu block chạm đáy hoặc block khác (block sẽ trở lại vị trí cũ).
 */
bool GameLogicService::MoveDown(Block& block, const Grid& grid) const {
    block.MoveDown();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.MoveUp();
        return false;
    }
    return true;
}

/**
 * @brief Xoay block nếu có thể.
 *
 * @param block Khối Tetris cần xoay.
 * @param grid Lưới trò chơi dùng để kiểm tra va chạm.
 * @return true Nếu xoay thành công.
 * @return false Nếu không thể xoay (block sẽ trở lại trạng thái cũ).
 */
bool GameLogicService::Rotate(Block& block, const Grid& grid) const {
    block.Rotate();
    if (!grid.IsValidPosition(block.GetCellPositions())) {
        block.RotateBack();
        return false;
    }
    return true;
}

/**
 * @brief Khóa block vào lưới (sau khi block chạm đáy hoặc khối khác).
 *
 * @param grid Lưới trò chơi để cập nhật cell.
 * @param block Khối cần được cố định vào grid.
 * @throw std::runtime_error Nếu số lượng cell và số lượng màu không khớp.
 */
void GameLogicService::LockBlock(Grid& grid, const Block& block) const {
    const auto& positions = block.GetCellPositions();
    std::vector<Color> colors = block.GetCellColor();

    // Nếu chỉ có 1 màu, nhân bản màu để match số cell
    if (colors.size() == 1 && positions.size() > 1) {
        colors = std::vector<Color>(positions.size(), colors[0]);
    }

    // Nếu mismatch, throw để phát hiện lỗi sớm
    if (positions.size() != colors.size()) {
        throw std::runtime_error("LockBlock error: positions.size() != colors.size()");
    }

    for (size_t i = 0; i < positions.size(); ++i) {
        const auto& pos = positions[i];
        if (pos.row >= 0 && pos.row < grid.GetRows() &&
            pos.column >= 0 && pos.column < grid.GetColumns()) {
            grid.SetCell(pos.row, pos.column, colors[i]);
        } else {
            // Log hoặc bỏ qua nếu vị trí ngoài grid
        }
    }
}

/**
 * @brief Xóa các hàng đầy trong lưới.
 *
 * @param grid Lưới trò chơi cần xử lý.
 * @return int Số hàng đã xóa.
 */
int GameLogicService::ClearLines(Grid& grid) const {
    return grid.ClearFullLines();
}

/**
 * @brief Kiểm tra trò chơi có kết thúc hay chưa.
 *
 * @param grid Lưới trò chơi.
 * @return true Nếu có block xuất hiện ở hàng trên cùng (game over).
 * @return false Nếu trò chơi vẫn tiếp tục.
 */
bool GameLogicService::IsGameOver(const Grid& grid) const {
    return grid.HasBlockAtTop();
}
