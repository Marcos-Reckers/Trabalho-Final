#include "raylib.h"
#include "pauseMenu.h"
#include "settings.h"

void game(cfg *settings)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    settings->frames_counter = 0;
    settings->exit_window = false;
    settings->pause = false;
    settings->pause_select = 0;
    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose())
    {

        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ESCAPE))
        {   
            PlaySound(fx_select);
            WaitTime(10);
            settings->pause = true;
        }

        else
        {
            settings->frames_counter++;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        pauseMenu(settings);

        DrawText("Hello World!", 100, 100, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            settings->select = 4;
            break;
        }

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------
}