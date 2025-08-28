#include "GameController.h"

/**
 * @brief Khởi tạo GameController với số hàng, cột và kích thước ô.
 * @param rows Số hàng của lưới game.
 * @param cols Số cột của lưới game.
 * @param cellSize Kích thước của mỗi ô (pixel).
 */
GameController::GameController(int rows, int cols, int cellSize)
    : grid_(rows, cols),
      current_block_(nullptr), 
      next_block_(nullptr),    
      renderer_(cellSize) {} 
        
/**
 * @brief Khởi tạo trạng thái ban đầu của game (khối đầu tiên, nhạc, điểm).
 */
void GameController::Init() {
    current_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    audio_.Init();
    audio_.PlayBackgroundMusic();
    score_.LoadBestScore();
}

/**
 * @brief Reset toàn bộ game về trạng thái ban đầu.
 */
void GameController::Reset() {
    grid_ = Grid(grid_.GetRows(), grid_.GetColumns());
    current_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    drop_timer_ = 0.0f;
    score_.Reset();
    is_game_over_ = false;
}

/**
 * @brief Sinh block mới để thay thế block hiện tại. 
 * Nếu game over thì lưu điểm cao nhất.
 */
void GameController::SpawnNewBlock() {
    current_block_ = std::move(next_block_);
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    if (logic_.IsGameOver(grid_)) {
        is_game_over_ = true;
        score_.SaveBestScore(); ///< Lưu điểm cao nhất khi game over
    }
}

/**
 * @brief Cập nhật trạng thái game theo thời gian và xử lý input.
 * @param deltaTime Thời gian trôi qua giữa 2 frame (giây).
 */
void GameController::Update(float deltaTime) {
    if (is_game_over_) return;

    drop_timer_ += deltaTime;

    // Xử lý input bàn phím
    if (IsKeyPressed(KEY_LEFT)) {
        logic_.MoveLeft(*current_block_, grid_);
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        logic_.MoveRight(*current_block_, grid_);
    }
    if (IsKeyPressed(KEY_UP)) {
        if (logic_.Rotate(*current_block_, grid_)) {
            audio_.PlayRotateEffect();
        }
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (logic_.MoveDown(*current_block_, grid_)) {
        }
    }
    if (IsKeyPressed(KEY_Q)) {
        CloseWindow(); ///< Raylib sẽ đóng cửa sổ game
    }
    
    if (IsKeyPressed(KEY_SPACE)) {
        /// Rơi block xuống hết trước
        while (logic_.MoveDown(*current_block_, grid_)) { }
        /// Sau đó lock block lại
        logic_.LockBlock(grid_, *current_block_);
        audio_.PlayClearEffect();

        int cleared = logic_.ClearLines(grid_);
        if (cleared > 0) score_.AddScore(cleared, 0);

        SpawnNewBlock();
    }

    // Rơi tự động sau khoảng drop_interval_
    if (drop_timer_ >= drop_interval_) {
        if (!logic_.MoveDown(*current_block_, grid_)) {
            logic_.LockBlock(grid_, *current_block_);
            audio_.PlayClearEffect();

            int cleared = logic_.ClearLines(grid_);
            if (cleared > 0) {
                score_.AddScore(cleared,0);
            }

            SpawnNewBlock();
        }
        drop_timer_ = 0.0f;
    }
}

/**
 * @brief Vẽ lưới và block hiện tại lên màn hình.
 */
void GameController::Draw() {
    renderer_.Draw(grid_, 50, 50);

    if (current_block_) {
        current_block_->Draw(50, 50);
    }
}

/**
 * @brief Vẽ block tiếp theo (preview).
 */
void GameController::DrawNextBlock() const {
    if (next_block_) {
        next_block_->DrawPreview(700, 100); ///< Vị trí vẽ khối tiếp theo
    }
}

/**
 * @brief Lấy điểm số hiện tại của người chơi.
 * @return Điểm số hiện tại.
 */
int GameController::GetScore() const {
    return score_.GetScore();
}

/**
 * @brief Lấy điểm cao nhất từng đạt được.
 * @return Điểm cao nhất.
 */
int GameController::GetBestScore() const {
    return score_.GetBestScore();
}

/**
 * @brief Kiểm tra game có kết thúc hay chưa.
 * @return true nếu game over, ngược lại false.
 */
bool GameController::IsGameOver() const {
    return is_game_over_;
}
