#include "GameController.h"
#include "../source2/Model/BlockService/RandomBlockGenerator.h" // Hàm tạo block ngẫu nhiên

GameController::GameController(int rows, int cols, int cellSize)
    : grid_(rows, cols),
      renderer_(cellSize),
      current_block_(nullptr),
      next_block_(nullptr) {}

void GameController::Init() {
    current_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    audio_.Init();
    audio_.PlayBackgroundMusic();
    score_.LoadBestScore();
}

void GameController::Reset() {
    grid_ = Grid(grid_.GetRows(), grid_.GetColumns());
    current_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    drop_timer_ = 0.0f;
    score_.Reset();
    is_game_over_ = false;
}

void GameController::SpawnNewBlock() {
    current_block_ = std::move(next_block_);
    next_block_ = RandomBlockGenerator::Generate(grid_.GetColumns());

    if (logic_.IsGameOver(grid_)) {
        is_game_over_ = true;
    }
}

void GameController::Update(float deltaTime) {
    if (is_game_over_) return;

    drop_timer_ += deltaTime;

    // Xử lý input
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
            score_.AddScore(0, 1); // 1 điểm cho mỗi lần rơi nhanh
        }
    }

    // Rơi tự động
    if (drop_timer_ >= drop_interval_) {
        if (!logic_.MoveDown(*current_block_, grid_)) {
            logic_.LockBlock(grid_, *current_block_);
            audio_.PlayClearEffect();

            int cleared = logic_.ClearLines(grid_);
            if (cleared > 0) {
                score_.AddScore(cleared, 0);
            }

            SpawnNewBlock();
        }
        drop_timer_ = 0.0f;
    }
}

void GameController::Draw() {
    renderer_.Draw(grid_, 50, 50);

    if (current_block_) {
        current_block_->Draw(50, 50);
    }

    // Gợi ý: có thể thêm vẽ next_block_ và điểm số tại đây
}

int GameController::GetScore() const {
    return score_.GetScore();
}

int GameController::GetBestScore() const {
    return score_.GetBestScore();
}

bool GameController::IsGameOver() const {
    return is_game_over_;
}
