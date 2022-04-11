#include "raylib.h"
#include "settings.h"

void drawEnemy(cfg *settings)
{
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        DrawRectangle(settings->enemy_pos[i].x, settings->enemy_pos[i].y, settings->enemy_pos[i].width, settings->enemy_pos[i].height, WHITE);
    }
}