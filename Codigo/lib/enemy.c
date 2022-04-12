#include "raylib.h"
#include "settings.h"

void spawnEnemy(cfg *settings)
{
    settings->enemy_time_spawn++;
    if (settings->enemy_lives[settings->enemy_counter] == 0 && settings->enemy_time_spawn > 4 * 60 && settings->enemy_on_screen <= 4 && settings->enemy_counter < settings->enemy_amount)
    {
        do
        {
            settings->enemy_collision_check = false;
            settings->enemy_pos[settings->enemy_counter].x = GetRandomValue(0, settings->game_screen_width - settings->enemy_pos[settings->enemy_counter].width);
            settings->enemy_pos[settings->enemy_counter].y = GetRandomValue(50, settings->game_screen_height - settings->enemy_pos[settings->enemy_counter].height);

            // collision testing
            for (int j = 0; j < settings->enemy_counter; j++)
            {
                if (CheckCollisionRecs(settings->enemy_pos[settings->enemy_counter], settings->enemy_pos[j]) && settings->enemy_counter != j)
                {
                    settings->enemy_collision_check = true;
                }
            }
        } while (settings->enemy_collision_check);

        settings->enemy_lives[settings->enemy_counter] = 1;
        settings->enemy_counter++;
        settings->enemy_on_screen++;
        settings->enemy_time_spawn = 0;
    }
}

void drawEnemy(cfg *settings)
{
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        if (settings->enemy_lives[i] > 0)
        {
            DrawRectangle(settings->enemy_pos[i].x, settings->enemy_pos[i].y, settings->enemy_pos[i].width, settings->enemy_pos[i].height, WHITE);
        }
    }
}