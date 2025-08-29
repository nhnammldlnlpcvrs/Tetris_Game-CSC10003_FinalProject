#pragma once
#include "raylib.h"

/**
 * @file AudioService.h
 * @brief Quản lý âm thanh và nhạc nền cho trò chơi Tetris.
 * 
 * Áp dụng Design Pattern: Service Locator.
 * Cung cấp interface thống nhất để phát âm thanh và cập nhật nhạc nền.
 */

class AudioService {
public:
    AudioService();
    ~AudioService();

    void Init();                      // Khởi tạo hệ thống âm thanh và load file
    void PlayRotateEffect();         // Phát âm khi xoay khối
    void PlayClearEffect();          // Phát âm khi xóa dòng
    void PlayBackgroundMusic();      // Phát nhạc nền (resume nếu bị pause)
    Music& GetBackgroundMusic();     // Cập nhật stream mỗi frame

private:
    Sound rotate_sound_{};           // Âm xoay khối
    Sound clear_sound_{};            // Âm xóa dòng
    Music background_music_{};       // Nhạc nền

    bool is_initialized_ = false;    // Tránh double free nếu Init thất bại
};
