#include "AudioService.h"

constexpr const char* ROTATE_SOUND_PATH = "assets/sounds/rotate.mp3";
constexpr const char* CLEAR_SOUND_PATH  = "assets/sounds/clear.mp3";
constexpr const char* MUSIC_PATH        = "assets/sounds/hold_on_tight_aespa.mp3";

/**
 * @brief Khởi tạo AudioService nhưng chưa load tài nguyên.
 * 
 * Constructor này không thực hiện logic nặng, việc khởi tạo thật sự được thực hiện trong Init().
 */
AudioService::AudioService() {
    // Constructor không thực hiện logic nặng
}

/**
 * @brief Khởi tạo hệ thống âm thanh và load các hiệu ứng + nhạc nền.
 * 
 * - Gọi InitAudioDevice() để khởi tạo thiết bị âm thanh.  
 * - Load âm thanh xoay khối, âm thanh xóa dòng, và nhạc nền.  
 * - Tự động phát nhạc nền ngay khi khởi tạo.  
 */
void AudioService::Init() {
    InitAudioDevice();

    rotate_sound_ = LoadSound(ROTATE_SOUND_PATH);
    clear_sound_  = LoadSound(CLEAR_SOUND_PATH);
    background_music_ = LoadMusicStream(MUSIC_PATH);

    PlayMusicStream(background_music_);  // Tự động phát nhạc ngay
    is_initialized_ = true;
}

/**
 * @brief Giải phóng tài nguyên âm thanh khi AudioService bị hủy.
 * 
 * - Giải phóng sound effect.  
 * - Giải phóng nhạc nền.  
 * - Đóng thiết bị âm thanh.  
 */
AudioService::~AudioService() {
    if (!is_initialized_) return;

    UnloadSound(rotate_sound_);
    UnloadSound(clear_sound_);
    UnloadMusicStream(background_music_);
    CloseAudioDevice();
}

/**
 * @brief Phát hiệu ứng âm thanh khi xoay khối.
 */
void AudioService::PlayRotateEffect() {
    if (is_initialized_) {
        PlaySound(rotate_sound_);
    }
}

/**
 * @brief Phát hiệu ứng âm thanh khi xóa dòng.
 */
void AudioService::PlayClearEffect() {
    if (is_initialized_) {
        PlaySound(clear_sound_);
    }
}

/**
 * @brief Phát nhạc nền (background music).
 * 
 * Nếu đã gọi Init(), hàm này sẽ phát nhạc nền.
 */
void AudioService::PlayBackgroundMusic() {
    if (is_initialized_) {
        PlayMusicStream(background_music_);
    }
}

/**
 * @brief Trả về tham chiếu tới nhạc nền hiện tại.
 * 
 * @return Music& tham chiếu tới đối tượng nhạc nền.
 */
Music& AudioService::GetBackgroundMusic() {
    return background_music_;
}
