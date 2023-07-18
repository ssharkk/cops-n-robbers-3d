#include "raylib.h"
#include "scene.hpp"
#include "globals.hpp"
#include "playersettings.hpp"
// using namespace copsNrobbers3D;

namespace copsNrobbers3D
{
    extern int player_count;
}

// Scene drawing
void copsNrobbers3D::DrawScene(void)
{
    int count = 5;
    float spacing = 4;

    // Grid of cube trees on a plane to make a "world"
    DrawPlane({0, 0, 0}, {50, 50}, BEIGE); // Simple world plane

    for (float x = -count * spacing; x <= count * spacing; x += spacing)
    {
        for (float z = -count * spacing; z <= count * spacing; z += spacing)
        {
            DrawCube({x, 1.5f, z}, 1, 1, 1, LIME);
            DrawCube({x, 0.5f, z}, 0.25f, 1, 0.25f, BROWN);
        }
    }

    // Draw a cube at each player's position
    for (int i = 0; i < copsNrobbers3D::player_count; i++)
    {
        DrawCube(copsNrobbers3D::cameras_splitscreen[i].position, 1, 1, 1, RED);
    }
    // DrawCube(cameraPlayer2.position, 1, 1, 1, BLUE);
}