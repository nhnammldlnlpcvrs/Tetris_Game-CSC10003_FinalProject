#include "../source2/Infrastructure/Audio/AudioService.h"

constexpr const char* ROTATE_SOUND_PATH = "../assets/sounds/rotate.mp3";
constexpr const char* CLEAR_SOUND_PATH  = "../assets/sounds/clear.mp3";
constexpr const char* MUSIC_PATH        = "../assets/sounds/hold_on_tight_aespa.mp3";

AudioService::AudioService() {
    // Constructor không thực hiện logic nặng
}

void AudioService::Init() {
    InitAudioDevice();

    rotate_sound_ = LoadSound(ROTATE_SOUND_PATH);
    clear_sound_  = LoadSound(CLEAR_SOUND_PATH);
    background_music_ = LoadMusicStream(MUSIC_PATH);

    PlayMusicStream(background_music_);  // Tự động phát nhạc ngay
    is_initialized_ = true;
}

AudioService::~AudioService() {
    if (!is_initialized_) return;

    UnloadSound(rotate_sound_);
    UnloadSound(clear_sound_);
    UnloadMusicStream(background_music_);
    CloseAudioDevice();
}

void AudioService::PlayRotateEffect() {
    if (is_initialized_) {
        PlaySound(rotate_sound_);
    }
}

void AudioService::PlayClearEffect() {
    if (is_initialized_) {
        PlaySound(clear_sound_);
    }
}

void AudioService::PlayBackgroundMusic() {
    if (is_initialized_) {
        PlayMusicStream(background_music_);
    }
}

Music& AudioService::GetBackgroundMusic() {
    return background_music_;
}
