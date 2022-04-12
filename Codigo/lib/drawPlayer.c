#include "raylib.h"
#include "settings.h"

void drawPlayer(cfg *settings)
{
    DrawRectangleRec(settings->player_pos, BLUE);
    DrawTexturePro(settings->player_texture, (Rectangle){0, 0, settings->player_texture.width, settings->player_texture.height}, settings->player_pos, settings->player_texture_origin, settings->player_rotation, WHITE); // Draw player
}