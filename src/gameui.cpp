#include "gameui.hpp"

#include "raylib.h"
#include "globals.hpp"

using namespace copsNrobbers3D;
namespace copsNrobbers3D
{
    extern int player_count;
    extern std::vector<PlayerSettings> players_settings;

    extern Camera cameras_splitscreen[];
    extern RenderTexture screens_splitscreen[];
    extern int slice_height_splitscreen;
    extern Rectangle splitScreenRect;
}



void initCameras() 
{
    for (int i = 0; i < copsNrobbers3D::player_count; i++)
    {
        // Setup player i camera and screen
        cameras_splitscreen[i] = {};
        Camera *camera = &cameras_splitscreen[i];
        camera->fovy = 45.0f;
        camera->up.y = 1.0f;
        camera->target.y = 1.0f;
        camera->position.z = -3.0f;
        camera->position.y = 1.0f;

        screens_splitscreen[i] = LoadRenderTexture(screenWidth, slice_height_splitscreen);
    }
}


void RefreshCameraLayout()
{
    slice_height_splitscreen = screenHeight / player_count;
    splitScreenRect.width = screenWidth;
    splitScreenRect.height = (float)-slice_height_splitscreen;
    for (int i = 0; i < player_count; i++)
    {
        // Setup player i camera and screen
        cameras_splitscreen[i] = {};
        Camera *camera = &cameras_splitscreen[i];
        camera->fovy = 45.0f;
        camera->up.y = 1.0f;
        camera->target.y = 1.0f;
        camera->position.z = -3.0f;
        camera->position.y = 1.0f;

        screens_splitscreen[i] = LoadRenderTexture(screenWidth, slice_height_splitscreen);
    }
}

void DrawCamerasLayout()
{
    for (int i = 0; i < copsNrobbers3D::player_count; i++)
    {
        DrawTextureRec(screens_splitscreen[i].texture, splitScreenRect, {0, (float)slice_height_splitscreen * i}, WHITE);
    }
}