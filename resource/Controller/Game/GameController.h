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
 * @brief Quản lý tương tác giữa người dùng và logic trò chơi.
 */
/**
 * @class GameController
 * @brief Quản lý luồng trò chơi Tetris, xử lý logic, điểm số và hiển thị.
 */
class GameController {
public:
    GameController(int rows, int cols, int cellSize);

    void Init();
    void Update(float deltaTime);
    void Draw();
    void DrawNextBlock() const;
    void Reset();

    int GetScore() const;
    int GetBestScore() const;
    bool IsGameOver() const;

private:
    Grid grid_;
    std::unique_ptr<Block> current_block_;
    std::unique_ptr<Block> next_block_;

    GridRenderer renderer_;
    GameLogicService logic_;
    ScoreService score_;
    AudioService audio_;

    float drop_timer_ = 0.0f;
    float drop_interval_ = 0.5f;

    bool is_game_over_ = false;

    void SpawnNewBlock();
};