#pragma once

/**
 * @file app.h
 * @brief Khai báo lớp App – điểm khởi chạy chính của ứng dụng Tetris.
 */

/**
 * @class App
 * @brief Lớp đại diện cho toàn bộ ứng dụng, chịu trách nhiệm khởi động và điều phối trò chơi.
 *
 * Lớp này thường là nơi khởi tạo cửa sổ, vòng lặp game chính và gọi các thành phần phụ như Game, UI, Audio.
 */
class App {
public:
    /**
     * @brief Chạy ứng dụng chính, khởi động vòng lặp game.
     */
    void Run();
};
