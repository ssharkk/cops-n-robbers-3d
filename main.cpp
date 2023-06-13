#include "raylib.h"
#include <math.h>

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
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        delta = GetFrameTime();
        nowTime = GetTime();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircleV(mousePosition, pointerRadius * delta * 165 * (sin(nowTime) + 1), LIGHTGRAY);
            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}