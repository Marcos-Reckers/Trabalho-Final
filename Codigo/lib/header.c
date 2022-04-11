#include "raylib.h"
#include "settings.h"

void pauseMenu(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    settings->player_lives = 3;
    settings->player_score = 1600;

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
        ClearBackground(BLACK);

        DrawRectangle(0, 0, GetScreenWidth(), 50, RAYWHITE);
        for (int i = 0; i <= settings->player_lives; i++)
        {
            DrawTexture(settings->right_tank, 10 + (10 * i), 10, WHITE);
        }

        DrawRectangle(700, 10, 70, 20, RAYWHITE);

        //--------------------------------------------------
    
}
