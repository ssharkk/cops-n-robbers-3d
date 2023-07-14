#include <raylib.h>
#include <math.h>

#define RAYGUI_IMPLEMENTATION
// #include "raygui.h"                 // Required for GUI controls
#include <raygui.h>                 // Required for GUI controls

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int pointerRadius = 16;

    InitWindow(screenWidth, screenHeight, "Cops'N'Robbers 3D");

    Vector2 mousePosition = { GetScreenWidth() / 2.0f , GetScreenHeight() / 2.0f };
    double delta = 1;
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
        delta = GetFrameTime();
        nowTime = GetTime();
        if (prev_gui_check != gui_check) {
            if (gui_check) SetTargetFPS(60);
            else SetTargetFPS(165);
            prev_gui_check = gui_check;
        }
        if (play) {
            printf("PLAY now!");
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            //ClearBackground(RAYWHITE);
            ClearBackground(Fade(MAROON, 0.8f));
            DrawCircleV(mousePosition, pointerRadius * delta * 165 * (sin(nowTime) + 1) + 20, LIGHTGRAY);
            DrawFPS(10, 10);
            GuiCheckBox({ 600, 320, 20, 20 }, "My Checkbox", & gui_check);
            GuiValueBox(play_button, "Number of Players", &players, 2, 8, gui_check);
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