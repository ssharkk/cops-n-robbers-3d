#include "globals.hpp"
#include <string>
#include <raylib.h>
#include <raymath.h>
#include <math.h>

#define RAYGUI_IMPLEMENTATION
// #include "raygui.h"                 // Required for GUI controls
#include <raygui.h> // Required for GUI controls

#include "scene.hpp"
#include "playersettings.hpp"
#include "gameui.hpp"

// namespace copsNrobbers3D
// {
//     extern int playerCount;
// }

using namespace copsNrobbers3D;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int pointerRadius = 16;

    InitWindow(screenWidth, screenHeight, "Cops'N'Robbers 3D");

    initCameras();

    Vector2 mousePosition = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    double deltaFrameTime;
    double nowTime;
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(165);

    bool gui_check = false, prev_gui_check = true;
    Rectangle playercount_field_rect = {100, 50, 80, 100};
    int players = 2;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        deltaFrameTime = GetFrameTime();
        nowTime = GetTime();
        if (prev_gui_check != gui_check)
        {
            if (gui_check)
                SetTargetFPS(60);
            else
                SetTargetFPS(165);
            prev_gui_check = gui_check;

            player_count = players;
            RefreshCameraLayout();
            
        }

        // Test input controls on player #3
        if (player_count <= 4)
        {
            // Turn player left or right
            Vector3 target, position;
            for (int i = 0; i < copsNrobbers3D::player_count; i++)
            {
                target = cameras_splitscreen[i].target, position = cameras_splitscreen[i].position;
                float forward_mult = 0;
                if (IsKeyDown(players_settings[i].key_forward)) {
                    forward_mult = 1;
                }

                if (IsKeyDown(players_settings[i].key_left) & IsKeyDown(players_settings[i].key_right)) {
                    if (IsKeyUp(players_settings[i].key_forward))
                        forward_mult = -1;
                }
                else if (IsKeyDown(players_settings[i].key_left))
                {
                    cameras_splitscreen[i].target = Vector3(Vector3Add(position, Vector3RotateByAxisAngle(Vector3Subtract(target, position), {0, 1, 0}, deltaFrameTime * 1)));
                }
                else if (IsKeyDown(players_settings[i].key_right))
                {
                    cameras_splitscreen[i].target = Vector3(Vector3Add(position, Vector3RotateByAxisAngle(Vector3Subtract(target, position), {0, 1, 0}, -deltaFrameTime * 1)));
                }
                // Move player forward
                
                if (forward_mult != 0)
                {
                    target = cameras_splitscreen[i].target, position = cameras_splitscreen[i].position;
                    Vector3 move = Vector3Scale(Vector3Subtract(target, position), forward_mult * deltaFrameTime);
                    cameras_splitscreen[i].position = Vector3(Vector3Add(position, move));
                    cameras_splitscreen[i].target = Vector3(Vector3Add(target, move));
                }
            }
        }

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------

        // Draw Player1 view to the render texture
        for (int i = 0; i < copsNrobbers3D::player_count; i++)
        {
            BeginTextureMode(screens_splitscreen[i]);
            ClearBackground(SKYBLUE);
            BeginMode3D(cameras_splitscreen[i]);
            DrawScene();
            EndMode3D();
            DrawText(("PLAYER" + std::to_string(i) + " " + players_settings[i].keys_hint + " to move").c_str(), 50, 10, 20, RED);
            EndTextureMode();
        }

        // Draw both views render textures to the screen side by side
        BeginDrawing();

            ClearBackground(Fade(MAROON, 0.8f));
            // ClearBackground(RAYWHITE);
            DrawCamerasLayout();

            // Draw gui overlay
            DrawFPS(10, 10);
            GuiCheckBox({120, 180, 20, 20}, "My Checkbox", &gui_check);
            GuiSpinner(playercount_field_rect, "Number of Players", &players, 2, MAX_PLAYERS, false);
            DrawText(std::to_string(player_count).c_str(), screenWidth / 2, 10, 20, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
