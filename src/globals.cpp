#include "globals.hpp"

namespace copsNrobbers3D
{

    extern int player_count { 3 };
    extern std::vector<PlayerSettings> players_settings = {
        {1, KEY_Q, KEY_W, KEY_E, "Q/W/E"},
        {2, KEY_A, KEY_S, KEY_D, "A/S/D"},
        {3, KEY_Z, KEY_X, KEY_C, "Z/X/C"},
        {4, KEY_I, KEY_O, KEY_P, "I/O/P"},
    };

    Camera cameras_splitscreen[copsNrobbers3D::MAX_PLAYERS];
    RenderTexture screens_splitscreen[copsNrobbers3D::MAX_PLAYERS];
    extern int slice_height_splitscreen = screenHeight/player_count;
    extern Rectangle splitScreenRect = {0.0f, 0.0f, (float)screens_splitscreen[0].texture.width, (float)-slice_height_splitscreen};

} // namespace copsNrobbers3D
