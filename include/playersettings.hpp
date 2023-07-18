#ifndef PLAYERSETTINGS_H
#define PLAYERSETTINGS_H

#include "raylib.h"

typedef struct PlayerSettings {
    int player_id;
    KeyboardKey key_left;
    KeyboardKey key_forward;
    KeyboardKey key_right;
};

#endif