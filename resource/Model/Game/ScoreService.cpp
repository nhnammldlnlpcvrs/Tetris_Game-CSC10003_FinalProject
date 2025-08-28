#include "ScoreService.h"
#include <filesystem>
namespace fs = std::filesystem;

/**
 * @brief Constructor của ScoreService.
 * 
 * Khởi tạo điểm hiện tại (score) và điểm cao nhất (bestScore),
 * sau đó tải điểm cao nhất từ file lưu trữ.
 */
ScoreService::ScoreService() : score(0), bestScore(0) {
    LoadBestScore();
}

/**
 * @brief Đặt lại điểm hiện tại về 0.
 */
void ScoreService::Reset() {
    score = 0;
}

/**
 * @brief Cộng điểm khi người chơi xóa được dòng hoặc thả nhanh block.
 * 
 * @param linesCleared Số dòng đã được xóa trong một lần.
 * @param dropPoints Điểm cộng thêm từ việc thả nhanh block.
 */
void ScoreService::AddScore(int linesCleared, int dropPoints) {
    static const int lineScores[] = {0, 100, 300, 500, 800};

    if (linesCleared > 0) {
        score += lineScores[linesCleared] + dropPoints;
    }

    if (score > bestScore) {
        bestScore = score;
    }
}

/**
 * @brief Lấy điểm hiện tại.
 * 
 * @return int Điểm hiện tại.
 */
int ScoreService::GetScore() const {
    return score;
}

/**
 * @brief Lấy điểm cao nhất.
 * 
 * @return int Điểm cao nhất đã lưu.
 */
int ScoreService::GetBestScore() const {
    return bestScore;
}

/**
 * @brief Tải điểm cao nhất từ file `assets/best_score.txt`.
 * 
 * Nếu file không tồn tại hoặc không đọc được, bestScore sẽ được đặt về 0.
 */
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

/**
 * @brief Lưu điểm cao nhất hiện tại vào file `assets/best_score.txt`.
 * 
 * Nếu file không mở được hoặc ghi lỗi, sẽ in thông báo lỗi ra console.
 */
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
