#pragma once

#include <fstream>
#include <iostream>

/**
 * @class ScoreService
 * @brief Quản lý điểm hiện tại và điểm cao nhất trong trò chơi.
 */
class ScoreService {
public:
    /**
     * @brief Khởi tạo ScoreService, tự động tải điểm cao nhất từ file.
     */
    ScoreService();

    /**
     * @brief Đặt lại điểm hiện tại về 0.
     */
    void Reset();

    /**
     * @brief Cộng thêm điểm dựa trên số dòng xóa và điểm rơi.
     * @param linesCleared Số dòng đã xóa.
     * @param dropPoints Điểm cộng thêm khi khối rơi nhanh.
     */
    void AddScore(int linesCleared, int dropPoints);

    /**
     * @brief Lấy điểm hiện tại.
     * @return Điểm hiện tại.
     */
    int GetScore() const;

    /**
     * @brief Lấy điểm cao nhất.
     * @return Điểm cao nhất.
     */
    int GetBestScore() const;

    /**
     * @brief Tải điểm cao nhất từ file.
     */
    void LoadBestScore();

    /**
     * @brief Lưu điểm cao nhất vào file.
     */
    void SaveBestScore();

private:
    int score;      ///< Điểm hiện tại.
    int bestScore;  ///< Điểm cao nhất.
};
