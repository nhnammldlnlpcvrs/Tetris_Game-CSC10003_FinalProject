#pragma once

#include <fstream>
#include <iostream>

/**
 * @class ScoreService
 * @brief Quản lý điểm, lưu và tải điểm cao nhất.
 */
class ScoreService {
public:
    ScoreService();

    void Reset();
    void AddScore(int linesCleared, int dropPoints);
    int GetScore() const;
    int GetBestScore() const;

    void LoadBestScore();
    void SaveBestScore();

private:
    int score;
    int bestScore;
};
