#include <raylib.h>
#include <raymath.h>
#include "globals.hpp"
#include "controller.hpp"

using namespace copsNrobbers3D;

void ApplyInput() {
    for (int i = 0; i < copsNrobbers3D::player_count; i++)
    {
        float forward_mult = 0, steer_mult = 0;
        // Go forward if pressing forward
        if (IsKeyDown(players_settings[i].key_forward)) {
            forward_mult = 1;
        }
        // Turn player left or right, or reverse if both except forward are pressed
        if (IsKeyDown(players_settings[i].key_left) & IsKeyDown(players_settings[i].key_right)) {
            if (IsKeyUp(players_settings[i].key_forward))
                forward_mult = -1;
        }
        else if (IsKeyDown(players_settings[i].key_left))
        {
            steer_mult = 1;
        }
        else if (IsKeyDown(players_settings[i].key_right))
        {
            steer_mult = -1;
        }
        ApplyControls(steer_mult, forward_mult, i);
    }
}

void ApplyControls(float steer, float gas, int player_id) {
    if (steer != 0) {
        Vector3 target = cameras_splitscreen[player_id].target, position = cameras_splitscreen[player_id].position;
        cameras_splitscreen[player_id].target = Steer(steer, target, position);
    }
    if (gas != 0) {
        Vector3 target = cameras_splitscreen[player_id].target, position = cameras_splitscreen[player_id].position;
        Vector3 move = EngineGas(gas, target, position);
        cameras_splitscreen[player_id].position = Vector3(Vector3Add(position, move));
        cameras_splitscreen[player_id].target = Vector3(Vector3Add(target, move));
    }
}

Vector3 Steer(float amount, Vector3 target, Vector3 position) {
    return Vector3(Vector3Add(position, Vector3RotateByAxisAngle(Vector3Subtract(target, position), {0, 1, 0}, amount * GetFrameTime())));
}

Vector3 EngineGas(float amount, Vector3 target, Vector3 position) {
    return Vector3Scale(Vector3Subtract(target, position), amount * GetFrameTime());
}