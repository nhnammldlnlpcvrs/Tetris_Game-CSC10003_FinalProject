#pragma once

#include "Model/Game/GameLogicService.h"
#include "Model/Game/ScoreService.h"
#include "Infrastructure/Audio/AudioService.h"
#include "View/Grid/GridRender.h"
#include "Core/Grid/Grid.h"
#include "Model/Block/Block.h"
#include "Model/BlockService/RandomBlockGenerator.h"
#include <raylib.h>
#include <memory>

/**
 * @class GameController
 * @brief Quản lý luồng trò chơi Tetris, bao gồm logic, điểm số, âm thanh và hiển thị.
 *
 * GameController chịu trách nhiệm kết nối các thành phần:
 * - Xử lý logic khối rơi (GameLogicService).
 * - Quản lý điểm và điểm cao (ScoreService).
 * - Chơi âm thanh (AudioService).
 * - Vẽ lưới và khối (GridRenderer).
 * - Sinh khối ngẫu nhiên (RandomBlockGenerator).
 */
class GameController {
public:
    /**
     * @brief Khởi tạo GameController với cấu hình lưới.
     * @param rows Số hàng của lưới.
     * @param cols Số cột của lưới.
     * @param cellSize Kích thước mỗi ô (pixel).
     */
    GameController(int rows, int cols, int cellSize);

    /**
     * @brief Khởi tạo trạng thái ban đầu (block đầu tiên, nhạc, điểm).
     */
    void Init();

    /**
     * @brief Cập nhật trạng thái game theo thời gian và input.
     * @param deltaTime Khoảng thời gian giữa 2 khung hình (giây).
     */
    void Update(float deltaTime);

    /**
     * @brief Vẽ lưới và block hiện tại.
     */
    void Draw();

    /**
     * @brief Vẽ block tiếp theo (preview).
     */
    void DrawNextBlock() const;

    /**
     * @brief Reset game về trạng thái ban đầu.
     */
    void Reset();

    /**
     * @brief Lấy điểm số hiện tại.
     * @return Điểm số hiện tại.
     */
    int GetScore() const;

    /**
     * @brief Lấy điểm cao nhất.
     * @return Điểm cao nhất.
     */
    int GetBestScore() const;

    /**
     * @brief Kiểm tra game có kết thúc hay chưa.
     * @return true nếu game over, ngược lại false.
     */
    bool IsGameOver() const;

private:
    /**
     * @brief Lưới trò chơi (ma trận chứa block).
     */
    Grid grid_;

    /**
     * @brief Block hiện tại mà người chơi đang điều khiển.
     */
    std::unique_ptr<Block> current_block_;

    /**
     * @brief Block sẽ xuất hiện tiếp theo.
     */
    std::unique_ptr<Block> next_block_;

    /**
     * @brief Bộ vẽ lưới và block.
     */
    GridRenderer renderer_;

    /**
     * @brief Xử lý logic của block (di chuyển, xoay, lock).
     */
    GameLogicService logic_;

    /**
     * @brief Quản lý điểm và điểm cao nhất.
     */
    ScoreService score_;

    /**
     * @brief Quản lý âm thanh nền và hiệu ứng.
     */
    AudioService audio_;

    /**
     * @brief Bộ đếm thời gian để xử lý block rơi tự động.
     */
    float drop_timer_ = 0.0f;

    /**
     * @brief Khoảng thời gian giữa mỗi lần block tự rơi (giây).
     */
    float drop_interval_ = 0.5f;

    /**
     * @brief Trạng thái kết thúc trò chơi.
     */
    bool is_game_over_ = false;

    /**
     * @brief Sinh block mới và cập nhật trạng thái game.
     */
    void SpawnNewBlock();
};
