#include <raylib.h>
#include <stdlib.h>
#include "settings.h"

void drawMap(cfg *settings)
{
    for (int line = 0; line < 15; line++)
    {
        for (int column = 0; column < 40 ; column++)
        {
            
            DrawTexturePro(settings->map_texture, (Rectangle){0, 0, settings->map_texture.width, settings->map_texture.height}, settings->map_pos[line][column],(Vector2){0,0}, 0, WHITE);
        }
        
    }
    
}