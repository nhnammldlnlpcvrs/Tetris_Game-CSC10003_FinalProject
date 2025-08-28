#pragma once

/**
 * @file App.h
 * @brief Khai báo lớp App – entry point của trò chơi Tetris.
 */

/**
 * @class App
 * @brief Quản lý vòng lặp chính và khởi động trò chơi Tetris.
 */
class App {
public:
    /**
     * @brief Hàm chạy ứng dụng chính.
     *
     * Khởi tạo cửa sổ, tải tài nguyên, chạy vòng lặp game cho đến khi thoát.
     */
    void Run();
};
