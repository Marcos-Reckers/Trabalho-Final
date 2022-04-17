#include "raylib.h"
#include "settings.h"

void drawPlayer(cfg *settings)
{
    DrawRectangleRec(settings->player_pos, BLUE);
}