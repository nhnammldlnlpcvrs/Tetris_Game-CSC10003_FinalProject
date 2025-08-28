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
    /**
     * @brief Constructor mặc định, không load tài nguyên ngay.
     */
    AudioService();

    /**
     * @brief Destructor, giải phóng tài nguyên âm thanh nếu đã khởi tạo.
     */
    ~AudioService();

    /**
     * @brief Khởi tạo hệ thống âm thanh và load các file âm thanh/nhạc nền.
     * 
     * - Gọi InitAudioDevice().  
     * - Load hiệu ứng xoay khối, xóa dòng.  
     * - Load và phát nhạc nền.  
     */
    void Init();

    /**
     * @brief Phát hiệu ứng âm thanh khi xoay khối.
     */
    void PlayRotateEffect();

    /**
     * @brief Phát hiệu ứng âm thanh khi xóa dòng.
     */
    void PlayClearEffect();

    /**
     * @brief Phát nhạc nền. 
     * 
     * Nếu nhạc đang tạm dừng thì tiếp tục phát (resume).
     */
    void PlayBackgroundMusic();

    /**
     * @brief Trả về tham chiếu đến nhạc nền để cập nhật mỗi frame.
     * 
     * @return Music& đối tượng nhạc nền đang phát.
     */
    Music& GetBackgroundMusic();

private:
    Sound rotate_sound_{};        ///< Âm thanh xoay khối.
    Sound clear_sound_{};         ///< Âm thanh xóa dòng.
    Music background_music_{};    ///< Nhạc nền của trò chơi.

    bool is_initialized_ = false; ///< Đảm bảo tránh giải phóng hai lần nếu Init thất bại.
};
