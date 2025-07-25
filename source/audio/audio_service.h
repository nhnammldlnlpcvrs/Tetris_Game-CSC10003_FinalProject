#pragma once
#include "raylib.h"

class AudioService {
public:
    AudioService();
    ~AudioService();

    void PlayRotateSound();
    void PlayClearSound();
    void PlayMusic();

    Music& GetMusic();
private:
    Sound rotateSound;
    Sound clearSound;
    Music music;
};
