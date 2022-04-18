#include "raylib.h"
#include "settings.h"

void moveEnemy(cfg *settings)
{
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        if (settings->enemy_lives[i] > 0)
        {
            if (settings->enemy_pos[i].x < (settings->player_pos.x + settings->player_pos.width) && settings->enemy_pos[i].x > settings->player_pos.x)
            {
                if (settings->enemy_pos[i].y - settings->player_pos.y > 0)
                {
                    settings->enemy_pos[i].y -= settings->enemy_speed;
                    settings->enemy_rotation[i] = 180;
                }
                else
                {
                    settings->enemy_pos[i].y += settings->enemy_speed;
                    settings->enemy_rotation[i] = 0;
                }
            }
            else if (settings->enemy_pos[i].y < (settings->player_pos.y + settings->player_pos.width) && settings->enemy_pos[i].y > settings->player_pos.y)
            {
                if (settings->enemy_pos[i].x - settings->player_pos.x > 0)
                {
                    settings->enemy_pos[i].x -= settings->enemy_speed;
                    settings->enemy_rotation[i] = 270;
                }
                else
                {
                    settings->enemy_pos[i].x += settings->enemy_speed;
                    settings->enemy_rotation[i] = 90;
                }
            }

            else 
            {
                switch (settings->enemy_random_rotate[i])
                {
                case 0:
                    settings->enemy_pos[i].x += settings->enemy_speed;
                    settings->enemy_rotation[i] = 0;
                    break;
                case 1:
                    settings->enemy_pos[i].x -= settings->enemy_speed;
                    settings->enemy_rotation[i] = 180;
                    break;

                case 2:
                    settings->enemy_pos[i].y -= settings->enemy_speed;
                    settings->enemy_rotation[i] = 270;
                    break;

                case 3:
                    settings->enemy_pos[i].y += settings->enemy_speed;
                    settings->enemy_rotation[i] = 90;
                    break;
                }
            }
        }
    }
}
