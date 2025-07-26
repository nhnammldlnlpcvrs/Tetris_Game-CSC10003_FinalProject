#include "audio_service.h"

/**
 * @brief Khởi tạo hệ thống âm thanh và tải các tệp âm thanh cần thiết.
 * 
 * Hàm khởi tạo sẽ:
 * - Khởi tạo thiết bị âm thanh (InitAudioDevice)
 * - Tải âm thanh xoay khối (rotate.mp3)
 * - Tải âm thanh xóa dòng (clear.mp3)
 * - Tải và phát nhạc nền (music.mp3)
 */
AudioService::AudioService() {
    InitAudioDevice();
    rotateSound = LoadSound("../assets/sounds/rotate.mp3");
    clearSound = LoadSound("../assets/sounds/clear.mp3");
    music = LoadMusicStream("../assets/sounds/hold_on_tight_aespa.mp3");
    PlayMusicStream(music);
}

/**
 * @brief Hủy các tài nguyên âm thanh và đóng thiết bị âm thanh.
 * 
 * Hàm hủy sẽ:
 * - Giải phóng các tệp âm thanh và nhạc nền
 * - Tắt thiết bị âm thanh
 */
AudioService::~AudioService() {
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

/**
 * @brief Phát âm thanh khi xoay khối.
 */
void AudioService::PlayRotateSound() {
    PlaySound(rotateSound);
}

/**
 * @brief Phát âm thanh khi xóa dòng.
 */
void AudioService::PlayClearSound() {
    PlaySound(clearSound);
}

/**
 * @brief Phát lại nhạc nền.
 */
void AudioService::PlayMusic() {
    PlayMusicStream(music);
}

/**
 * @brief Trả về tham chiếu đến đối tượng nhạc nền đang được phát.
 * 
 * @return Music& - tham chiếu đến đối tượng nhạc.
 */
Music& AudioService::GetMusic() {
    return music;
}
