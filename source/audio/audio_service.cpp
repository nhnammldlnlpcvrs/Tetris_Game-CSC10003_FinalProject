#include "audio_service.h"

AudioService::AudioService() {
    InitAudioDevice();
    rotateSound = LoadSound("../assets/sounds/rotate.mp3");
    clearSound = LoadSound("../assets/sounds/clear.mp3");
    music = LoadMusicStream("../assets/sounds/hold_on_tight_aespa.mp3");
    PlayMusicStream(music);
}

AudioService::~AudioService() {
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

void AudioService::PlayRotateSound() {
    PlaySound(rotateSound);
}

void AudioService::PlayClearSound() {
    PlaySound(clearSound);
}

void AudioService::PlayMusic() {
    PlayMusicStream(music);
}

Music& AudioService::GetMusic() {
    return music;
}
