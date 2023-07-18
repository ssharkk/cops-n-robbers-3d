#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include "raylib.h"
#include "playersettings.hpp"

namespace copsNrobbers3D
{
    //----------------------------------------------------------------------------------
    // Constants
    //----------------------------------------------------------------------------------

    const int MAX_PLAYERS = 9;
    
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //----------------------------------------------------------------------------------
    // Global Variables
    //----------------------------------------------------------------------------------

    // Font font = { 0 };
    // Music music = { 0 };
    // int endingStatus = 0;           // 1 - Win, 2 - Lose
    // char *sampleFilename = NULL;    // Required for custom music file

    extern int player_count;
    extern std::vector<PlayerSettings> players_settings;

    extern Camera cameras_splitscreen[];
    extern RenderTexture screens_splitscreen[];
    extern int slice_height_splitscreen;

} // namespace copsNrobbers3D

#endif
