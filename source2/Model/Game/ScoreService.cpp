#include "ScoreService.h"


ScoreService::ScoreService() : score(0), bestScore(0) {
    LoadBestScore();
}

void ScoreService::Reset() {
    score = 0;
}

void ScoreService::AddScore(int linesCleared, int dropPoints) {
    static const int lineScores[] = {0, 100, 300, 500, 800};
    score += lineScores[linesCleared] + dropPoints;

    if (score > bestScore) {
        bestScore = score;
    }
}

int ScoreService::GetScore() const {
    return score;
}

int ScoreService::GetBestScore() const {
    return bestScore;
}

void ScoreService::LoadBestScore() {
    std::ifstream file("best_score.txt");
    if (file >> bestScore) {
        return;
    }
    bestScore = 0;
}

void ScoreService::SaveBestScore() {
    std::ofstream file("best_score.txt");
    if (file) {
        file << bestScore;
    }
}
