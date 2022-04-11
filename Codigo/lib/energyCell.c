#include "raylib.h"
#include <math.h>
#include "settings.h"

void energyCell(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    int roll = GetRandomValue(0, 16);
    //------------------------------------------------------

    // Main window loop
    //------------------------------------------------------
    if (IsKeyReleased(KEY_C))
    {   
        settings->cell_pos.x = GetRandomValue(0, 19);
        settings->cell_pos.y = GetRandomValue(1, 11);
        settings->energy_cell_active = true;
    }

    if (!roll && !((settings->frames_counter) % 5))
    {
        settings->energy_cell_active = false;
    }
  
    if (!settings->energy_cell_active)
    {
        // Draw
        //--------------------------------------------------
        DrawTexture(settings->energy_cell, settings->cell_pos.x * 50, settings->cell_pos.y * 50, WHITE);
        //--------------------------------------------------
    }
    
}