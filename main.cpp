#include <raylib.h>
#include <math.h>

#define RAYGUI_IMPLEMENTATION
// #include "raygui.h"                 // Required for GUI controls
#include <raygui.h>                 // Required for GUI controls


Camera cameraPlayer1 = { 0 };
Camera cameraPlayer2 = { 0 };

// Scene drawing
void DrawScene(void)
{
    int count = 5;
    float spacing = 4;

    // Grid of cube trees on a plane to make a "world"
    DrawPlane({ 0, 0, 0 }, { 50, 50 }, BEIGE); // Simple world plane

    for (float x = -count*spacing; x <= count*spacing; x += spacing)
    {
        for (float z = -count*spacing; z <= count*spacing; z += spacing)
        {
            DrawCube( { x, 1.5f, z }, 1, 1, 1, LIME);
            DrawCube( { x, 0.5f, z }, 0.25f, 1, 0.25f, BROWN);
        }
    }

    // Draw a cube at each player's position
    DrawCube(cameraPlayer1.position, 1, 1, 1, RED);
    DrawCube(cameraPlayer2.position, 1, 1, 1, BLUE);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int pointerRadius = 16;

    InitWindow(screenWidth, screenHeight, "Cops'N'Robbers 3D");


    // Setup player 1 camera and screen
    cameraPlayer1.fovy = 45.0f;
    cameraPlayer1.up.y = 1.0f;
    cameraPlayer1.target.y = 1.0f;
    cameraPlayer1.position.z = -3.0f;
    cameraPlayer1.position.y = 1.0f;

    RenderTexture screenPlayer1 = LoadRenderTexture(screenWidth/2, screenHeight/2);

    // Setup player two camera and screen
    cameraPlayer2.fovy = 45.0f;
    cameraPlayer2.up.y = 1.0f;
    cameraPlayer2.target.y = 3.0f;
    cameraPlayer2.position.x = -3.0f;
    cameraPlayer2.position.y = 3.0f;

    RenderTexture screenPlayer2 = LoadRenderTexture(screenWidth / 2, screenHeight/2);

    Rectangle splitScreenRect = { 0.0f, 0.0f, (float)screenPlayer1.texture.width, (float)-screenPlayer1.texture.height };

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
        }
        if (play) {
            printf("PLAY now!");
        }

        cameraPlayer1.position.x += deltaFrameTime;
        cameraPlayer1.target.x += deltaFrameTime;
        cameraPlayer2.target.x += deltaFrameTime;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        // Draw Player1 view to the render texture
        BeginTextureMode(screenPlayer1);
            ClearBackground(SKYBLUE);
            BeginMode3D(cameraPlayer1);
                DrawScene();
            EndMode3D();
            DrawText("PLAYER1 W/S to move", 10, 10, 20, RED);
        EndTextureMode();

        // Draw Player2 view to the render texture
        BeginTextureMode(screenPlayer2);
            ClearBackground(SKYBLUE);
            BeginMode3D(cameraPlayer2);
                DrawScene();
            EndMode3D();
            DrawText("PLAYER2 UP/DOWN to move", 10, 10, 20, BLUE);
        EndTextureMode();
        
        // Draw both views render textures to the screen side by side
        BeginDrawing();
            ClearBackground(Fade(MAROON, 0.8f));
            // ClearBackground(RAYWHITE);

            DrawTextureRec(screenPlayer1.texture, splitScreenRect, { 0, 0 }, WHITE);
            DrawTextureRec(screenPlayer2.texture, splitScreenRect, { screenWidth/2.0f, 0 +screenHeight/3.0f }, WHITE);
            DrawTextureRec(screenPlayer1.texture, splitScreenRect, { 0, screenHeight/2.0f }, WHITE);
            DrawTextureRec(screenPlayer2.texture, splitScreenRect, { screenWidth/2.0f, screenHeight/2.0f}, WHITE);

            DrawCircleV(mousePosition, pointerRadius * deltaFrameTime * 165 * (sin(nowTime) + 1) + 20, LIGHTGRAY);
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