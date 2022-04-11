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
        settings->cell_x = GetRandomValue(0, 19);
        settings->cell_y = GetRandomValue(1, 11);
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
        DrawTexture(settings->energy_cell, settings->cell_x * 50, settings->cell_y * 50, WHITE);
        //--------------------------------------------------
    }
    
}