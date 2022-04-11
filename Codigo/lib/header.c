#include "raylib.h"
#include "settings.h"

void header(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    

    //------------------------------------------------------

    // Main window loop
    //------------------------------------------------------
    
    
        // Update
        //--------------------------------------------------
        settings->player_lives = 3;
        settings->player_score ++;
        
        //--------------------------------------------------

        // Draw
        //--------------------------------------------------

        DrawRectangle(0, 0, GetScreenWidth(), 50, DARKGRAY);

        for (int i = 1; i <= settings->player_lives; i++)
        {
            DrawTexture(settings->right_tank, 10 + (50 * i), 10, WHITE);
        }

        DrawRectangle(750, 10, 120, 30 , RED);

        DrawText("LEVEL X",GetScreenWidth() / 2 - MeasureText("LEVEL X", 20) , 10 , 40, YELLOW);

        //--------------------------------------------------
    
}
