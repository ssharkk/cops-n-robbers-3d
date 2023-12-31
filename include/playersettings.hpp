#pragma once
#include "raylib.h"
#include <string>

struct PlayerSettings {
    int player_id;
    KeyboardKey key_left;
    KeyboardKey key_forward;
    KeyboardKey key_right;
    std::string keys_hint;
};
