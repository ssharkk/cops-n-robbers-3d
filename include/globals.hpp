#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

namespace copsNrobbers3D
{

    const int MAX_PLAYERS = 9;
    extern int playerCount;
    extern Camera cameras_splitscreen[];
    extern RenderTexture screens_splitscreen[];


     //----------------------------------------------------------------------------------
    // Shared Variables Definition (global)
    //----------------------------------------------------------------------------------
    // Font font = { 0 };
    // Music music = { 0 };
    // int endingStatus = 0;           // 1 - Win, 2 - Lose
    // char *sampleFilename = NULL;    // Required for custom music file

    //----------------------------------------------------------------------------------
    // Module Variables Definition (local)
    //----------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //  int playerCount = 2;
    //  const int MAX_PLAYERS = 9;

    extern int slice_height_splitscreen;
    //  Camera cameras_splitscreen[MAX_PLAYERS];
    //  RenderTexture screens_splitscreen[MAX_PLAYERS];

} // namespace copsNrobbers3D

// namespace copsNrobbers3D
// {

//     const int MAX_PLAYERS = 9;
//     static int playerCount;
//     static Camera cameras_splitscreen[copsNrobbers3D::MAX_PLAYERS];
//     static RenderTexture screens_splitscreen[copsNrobbers3D::MAX_PLAYERS];


//      //----------------------------------------------------------------------------------
//     // Shared Variables Definition (global)
//     //----------------------------------------------------------------------------------
//     // Font font = { 0 };
//     // Music music = { 0 };
//     // int endingStatus = 0;           // 1 - Win, 2 - Lose
//     // char *sampleFilename = NULL;    // Required for custom music file

//     //----------------------------------------------------------------------------------
//     // Module Variables Definition (local)
//     //----------------------------------------------------------------------------------
//     const int screenWidth = 1280;
//     const int screenHeight = 720;

//     //  int playerCount = 2;
//     //  const int MAX_PLAYERS = 9;

//     static int slice_height_splitscreen = screenHeight/playerCount;
//     //  Camera cameras_splitscreen[MAX_PLAYERS];
//     //  RenderTexture screens_splitscreen[MAX_PLAYERS];

// } // namespace copsNrobbers3D

#endif
