#include "raylib.h"
#include "settings.h"
#include <math.h>
#include <stdlib.h>
#include "raymath.h"
#include "stdio.h"

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
        settings->player_bullet_time_shot = 0;
    }

    settings->player_bullet_pos.x += (settings->player_bullet_speed * cos(PI * (settings->player_bullet_rotation) / 180));
    settings->player_bullet_pos.y += (settings->player_bullet_speed * sin(PI * (settings->player_bullet_rotation) / 180));
    DrawTexturePro(settings->bullet_texture,(Rectangle){0, 0, settings->bullet_texture.width, settings->bullet_texture.height}, (Rectangle){settings->player_bullet_pos.x + (settings->player_bullet_pos.width / 2), settings->player_bullet_pos.y +(settings->player_bullet_pos.height / 2), settings->player_bullet_pos.width, settings->player_bullet_pos.height},(Vector2){settings->player_bullet_pos.width / 2, settings->player_bullet_pos.height / 2}, settings->player_bullet_rotation, WHITE);
    //----------------------------------------------------------------------------------------

    // Enemy bullets
    //----------------------------------------------------------------------------------------
    if (!settings->pause)
    {
        for (int i = 0; i < settings->enemy_amount; i++)
        {
            settings->enemy_bullet_time_shot[i]++;
            if (!GetRandomValue(0, 15) && settings->enemy_bullet_time_shot[i] > 1 * 60)
            {
                settings->enemy_bullet_time_active[i] = GetTime();
                settings->enemy_bullet_rotation[i] = settings->enemy_rotation[i];
                settings->enemy_bullet_pos[i] = (Rectangle){
                    settings->enemy_pos[i].x + (settings->enemy_pos[i].width / 2) + ((settings->enemy_pos[i].width / 2) * cos(PI * (settings->enemy_bullet_rotation[i]) / 180)) - (settings->enemy_bullet_pos[i].width / 2),
                    settings->enemy_pos[i].y + (settings->enemy_pos[i].height / 2) + ((settings->enemy_pos[i].height / 2) * sin(PI * (settings->enemy_bullet_rotation[i]) / 180)) - (settings->enemy_bullet_pos[i].height / 2),
                    10,
                    10};
                settings->enemy_bullet_speed[i] = 5;
                settings->enemy_bullet_time_shot[i] = 0;
            }

            settings->enemy_bullet_pos[i].x += (settings->enemy_bullet_speed[i] * cos(PI * (settings->enemy_bullet_rotation[i]) / 180));
            settings->enemy_bullet_pos[i].y += (settings->enemy_bullet_speed[i] * sin(PI * (settings->enemy_bullet_rotation[i]) / 180));
        }
    }
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        DrawTexturePro(settings->bullet_texture,(Rectangle){0, 0, settings->bullet_texture.width, settings->bullet_texture.height}, (Rectangle){settings->enemy_bullet_pos[i].x + (settings->enemy_bullet_pos[i].width / 2), settings->enemy_bullet_pos[i].y +(settings->enemy_bullet_pos[i].height / 2), settings->enemy_bullet_pos[i].width, settings->enemy_bullet_pos[i].height},(Vector2){settings->enemy_bullet_pos[i].width / 2, settings->enemy_bullet_pos[i].height / 2}, settings->enemy_bullet_rotation[i], WHITE);
    }
    // ---------------------------------------------------------------------------------------
}