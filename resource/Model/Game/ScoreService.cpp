#include "ScoreService.h"
#include <filesystem>
namespace fs = std::filesystem;


ScoreService::ScoreService() : score(0), bestScore(0) {
    LoadBestScore();
}

void ScoreService::Reset() {
    score = 0;
}

void ScoreService::AddScore(int linesCleared, int dropPoints) {
    static const int lineScores[] = {0, 100, 300, 500, 800};

    if (linesCleared > 0) {
        score += lineScores[linesCleared] + dropPoints;
    }

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
    std::string path = "assets/best_score.txt";
    std::cout << "Trying to open: " << path << std::endl;
    std::ifstream file(path);
    if (file.is_open()) {
        if (file >> bestScore) {
            std::cout << "Loaded best score: " << bestScore << " from " << path << std::endl;
        } else {
            std::cout << "Failed to read best score from " << path << ", setting to 0" << std::endl;
            bestScore = 0;
        }
        file.close();
    } else {
        std::cout << "Could not open " << path << ", best score set to 0" << std::endl;
        bestScore = 0;
    }
}

void ScoreService::SaveBestScore() {
    std::string path = "assets/best_score.txt";
    std::cout << "Trying to save to: " << path << std::endl;
    std::ofstream file(path);
    if (file.is_open()) {
        file << bestScore;
        file.flush();
        if (file.good()) {
            std::cout << "Saved best score: " << bestScore << " to " << path << std::endl;
        } else {
            std::cout << "Failed to write best score to " << path << std::endl;
        }
        file.close();
    } else {
        std::cout << "Could not open " << path << " to save best score" << std::endl;
    }
}