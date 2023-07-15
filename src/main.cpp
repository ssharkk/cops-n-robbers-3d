#include "globals.hpp"
#include<string>
#include <raylib.h>
#include <math.h>

#define RAYGUI_IMPLEMENTATION
// #include "raygui.h"                 // Required for GUI controls
#include <raygui.h>                 // Required for GUI controls


#include "scene.hpp"

// namespace copsNrobbers3D
// {
//     extern int playerCount;
// }

using namespace copsNrobbers3D;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    // const int screenWidth = 800;
    // const int screenHeight = 450;
    // cameras_splitscreen = new Camera[MAX_PLAYERS];
    // screens_splitscreen = new RenderTexture[MAX_PLAYERS];
    const int pointerRadius = 16;

    InitWindow(screenWidth, screenHeight, "Cops'N'Robbers 3D");

    for (int i = 0; i < copsNrobbers3D::playerCount; i++)
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
    
    Rectangle splitScreenRect = { 0.0f, 0.0f, (float)screens_splitscreen[0].texture.width, (float)-slice_height_splitscreen };

    Vector2 mousePosition = { GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f };

    double deltaFrameTime = 1;
    double nowTime = 1;
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(165);
    bool gui_check = false, prev_gui_check = true;
    Rectangle play_button = { 100, 50, 200, 100 };
    bool play = false;
    int players = 2;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        deltaFrameTime = GetFrameTime();
        nowTime = GetTime();
        if (prev_gui_check != gui_check) {
            if (gui_check) SetTargetFPS(60);
            else SetTargetFPS(165);
            prev_gui_check = gui_check;

            playerCount = players;
            slice_height_splitscreen = screenHeight/playerCount;
            splitScreenRect.height = (float)-slice_height_splitscreen;
            for (int i = 0; i < playerCount; i++)
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
        if (play) {
            printf("PLAY now!");
        }

        cameras_splitscreen[0].position.x += deltaFrameTime;
        cameras_splitscreen[0].target.x += deltaFrameTime;
        cameras_splitscreen[1].target.x += deltaFrameTime;
        // cameras_splitscreen[1]..x += deltaFrameTime;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        // Draw Player1 view to the render texture
        for (int i = 0; i < copsNrobbers3D::playerCount; i++)
        {
            BeginTextureMode(screens_splitscreen[i]);
                ClearBackground(SKYBLUE);
                BeginMode3D(cameras_splitscreen[i]);
                    DrawScene();
                EndMode3D();
                DrawText(("PLAYER"+std::to_string(i)+" W/S to move").c_str(), 10, 10, 20, RED);
            EndTextureMode();
        }
        
        // Draw both views render textures to the screen side by side
        BeginDrawing();
            ClearBackground(Fade(MAROON, 0.8f));
            // ClearBackground(RAYWHITE);
            for (int i = 0; i < copsNrobbers3D::playerCount; i++)
            {
                DrawTextureRec(screens_splitscreen[i].texture, splitScreenRect, { 0, (float) slice_height_splitscreen*i }, WHITE);
            }

            DrawCircleV(mousePosition, pointerRadius * deltaFrameTime * 165 * (sin(nowTime) + 1) + 20, LIGHTGRAY);
            DrawFPS(10, 10);
            GuiCheckBox({ 600, 320, 20, 20 }, "My Checkbox", & gui_check);
            GuiSpinner(play_button, "Number of Players", &players, 2, MAX_PLAYERS, false);
            DrawText(std::to_string(players).c_str(), screenWidth/2, 10, 20, GREEN);
            //GuiSpinner(play_button, "Number of Players", &players, 2, 8, false);
            //play = GuiLabelButton(play_button, "PLAY");

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
