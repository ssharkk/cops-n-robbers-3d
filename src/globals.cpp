#include "globals.hpp"

namespace copsNrobbers3D
{
    extern int playerCount { 8 };
    Camera cameras_splitscreen[copsNrobbers3D::MAX_PLAYERS];
    RenderTexture screens_splitscreen[copsNrobbers3D::MAX_PLAYERS];
    extern int slice_height_splitscreen = screenHeight/playerCount;
} // namespace copsNrobbers3D
