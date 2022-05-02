#include "raylib.h"
#include "settings.h"

void drawPlayer(cfg *settings)
{
    DrawTexturePro(settings->player_texture,(Rectangle){0, 0, settings->player_texture.width, settings->player_texture.height}, (Rectangle){settings->player_pos.x + (settings->player_pos.width / 2), settings->player_pos.y +(settings->player_pos.height / 2), settings->player_pos.width, settings->player_pos.height},(Vector2){settings->player_pos.width / 2, settings->player_pos.height / 2}, settings->player_rotation, WHITE);
}