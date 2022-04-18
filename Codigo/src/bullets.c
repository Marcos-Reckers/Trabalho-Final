#include "raylib.h"
#include "settings.h"
#include <math.h>
#include <stdlib.h>
#include "raymath.h"

void bullets(cfg *settings)
{
    // Player bullets
    //----------------------------------------------------------------------------------------
    settings->player_bullet_time_shot++;
    if (IsKeyPressed(KEY_SPACE) && settings->player_bullet_time_shot > 1 * 60)
    {
        settings->player_bullet_time_active = GetTime();
        settings->player_bullet_rotation = settings->player_rotation;
        settings->player_bullet_pos = (Rectangle){
            settings->player_pos.x + (settings->player_pos.width / 2) + ((settings->player_pos.width / 2) * cos(PI * (settings->player_bullet_rotation) / 180)) - (settings->player_bullet_pos.width / 2),
            settings->player_pos.y + (settings->player_pos.height / 2) + ((settings->player_pos.height / 2) * sin(PI * (settings->player_bullet_rotation) / 180)) - (settings->player_bullet_pos.height / 2),
            10,
            10};
        settings->player_bullet_speed = 5;
        settings->player_bullet_time_shot = 0;
    }

        settings->player_bullet_pos.x += (settings->player_bullet_speed * cos(PI * (settings->player_bullet_rotation) / 180));
        settings->player_bullet_pos.y += (settings->player_bullet_speed * sin(PI * (settings->player_bullet_rotation) / 180));
        DrawRectangleRec(settings->player_bullet_pos, WHITE);
    

    //----------------------------------------------------------------------------------------
}