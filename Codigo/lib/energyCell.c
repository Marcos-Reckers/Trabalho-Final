#include "raylib.h"
#include <math.h>
#include "settings.h"

void energyCell(cfg *settings)
{
    // Loop
    // -----------------------------------------------------
    
    // Player collision with EnergyCells
    //--------------------------------------------------------------------------------
    if (CheckCollisionRecs(settings->player_pos, settings->energy_cell_rec))
    {
        settings->energy_cell_active = true;
        settings->energy_cell_time_spawn = 0;
        settings->player_speed *= 1.5;
        settings->player_bullet_speed *= 1.5;
        settings->energy_cell_rec.x = settings->game_screen_width * 2;
        settings->energy_cell_rec.y = settings->game_screen_height * 2;
    }
    //--------------------------------------------------------------------------------

    // Energy cell spawn
    // -----------------------------------

    if (!settings->energy_cell_spawn)
    {
    
        if (!GetRandomValue(0, 16) && !settings->energy_cell_active)
        {

            settings->energy_cell_rec.x = GetRandomValue(0, settings->game_screen_width - settings->energy_cell_texture.width);
            settings->energy_cell_rec.y = GetRandomValue(50, settings->game_screen_height - settings->energy_cell_texture.height);
            settings->energy_cell_spawn = true;
        }
    }

    if (settings->energy_cell_spawn && !settings->energy_cell_active)
    {
        DrawTexture(settings->energy_cell_texture, settings->energy_cell_rec.x, settings->energy_cell_rec.y, WHITE);

        settings->energy_cell_time_spawn++;
        if (settings->energy_cell_time_spawn >= 5 * 60)
        {   
            
            settings->energy_cell_rec.x = settings->game_screen_width * 2;
            settings->energy_cell_rec.y = settings->game_screen_height * 2;
            settings->energy_cell_spawn = false;
            settings->energy_cell_time_spawn = 0;
        }
    }

    //------------------------------------

    // Energy cell acive
    // -----------------------------------
    if (settings->energy_cell_active)
    {

        settings->energy_cell_time_active++;
        if (settings->energy_cell_time_active >= 10 * 60)
        {
            settings->energy_cell_active = false;
            settings->energy_cell_spawn = true;
            settings->player_speed /= 1.5;
            settings->player_bullet_speed /= 1.5;
            settings->energy_cell_time_active = 0;
        }
    }
    //------------------------------------------------------------
}