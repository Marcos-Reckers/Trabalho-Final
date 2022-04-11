#include "raylib.h"
#include "settings.h"

void drawPlayer(cfg *settings)
{
    DrawRectangle(settings->player_pos.x, settings->player_pos.y, settings->player_pos.width, settings->player_pos.height, BLUE);
}