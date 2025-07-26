#pragma once
#include "raylib.h"

/**
 * @file audio_service.h
 * @brief Khai báo lớp AudioService dùng để quản lý và phát âm thanh trong trò chơi Tetris.
 */

/**
 * @class AudioService
 * @brief Cung cấp các chức năng phát nhạc và hiệu ứng âm thanh.
 *
 * Lớp này chịu trách nhiệm tải, phát và quản lý các âm thanh như: xoay khối, xóa dòng và nhạc nền.
 */
class AudioService {
public:
    /**
     * @brief Constructor. Tải âm thanh và nhạc nền từ tệp.
     */
    AudioService();

    /**
     * @brief Destructor. Giải phóng tài nguyên âm thanh.
     */
    ~AudioService();

    /**
     * @brief Phát hiệu ứng âm thanh khi xoay khối.
     */
    void PlayRotateSound();

    /**
     * @brief Phát hiệu ứng âm thanh khi xóa một hoặc nhiều dòng.
     */
    void PlayClearSound();

    /**
     * @brief Phát hoặc tiếp tục nhạc nền.
     */
    void PlayMusic();

    /**
     * @brief Lấy đối tượng nhạc nền hiện tại.
     * @return Tham chiếu đến biến Music.
     */
    Music& GetMusic();

private:
    /**
     * @brief Âm thanh khi xoay khối.
     */
    Sound rotateSound;

    /**
     * @brief Âm thanh khi xóa dòng.
     */
    Sound clearSound;

    /**
     * @brief Nhạc nền đang phát trong trò chơi.
     */
    Music music;
};
