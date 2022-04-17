#include "raylib.h"
#include "settings.h"

void movePlayer(cfg *settings)
{
    // Loop
    //---------------------------------
    if (IsKeyDown(KEY_RIGHT))
    {
        settings->player_pos.x += settings->player_speed;
        settings->player_rotation = 0;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        settings->player_pos.x -= settings->player_speed;
        settings->player_rotation = 180;
    }
    else if (IsKeyDown(KEY_UP))
    {
        settings->player_pos.y -= settings->player_speed;
        settings->player_rotation = 270;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        settings->player_pos.y += settings->player_speed;
        settings->player_rotation = 90;
    }

    //---------------------------------
}
