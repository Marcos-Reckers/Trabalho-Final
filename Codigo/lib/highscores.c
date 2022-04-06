#include "raylib.h"
#include <stdlib.h>

void Highscores(int *select)
{
    // Initialization
    // -----------------------------------------------------
    int highscores_select = 0;
    int frames_counter = 0;
    char highscores_options[5][50] = {"Marcos\0", "Pedro\0", "player 2\0", "player 3\0", "player 4\0"};
    bool exit_window = false;
    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    //-----------------------------------------------------------------------

    // Main window loop
    //-----------------------------------------------------------------------
    while (!WindowShouldClose() && !exit_window)
    {
        // Update
        //----------------------------------------------------------------------------------
        int screen_width = GetScreenWidth();
        int screen_height = GetScreenHeight();
        float scale = (screen_height * screen_width) / (600.0 * 800.0);

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fx_select);
            highscores_select += 1;
            highscores_select %= 6;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fx_select);
            highscores_select -= 1;
            if (highscores_select < 0)
            {
                highscores_select = 6 - abs(highscores_select % 6);
            }
            else
            {
                highscores_select %= 6;
            }
        }

        frames_counter++;
        //--------------------------------------------------------------------

        // Draw
        //--------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Highscores", screen_width / 2 - MeasureText("Highscores", 20 * scale), 0.050 * screen_height, 40 * scale, RAYWHITE);

        for (int i = 0; i < 6; i++)
        {
            if (i == highscores_select)
            {
                if (highscores_select == 5)
                {
                    if (IsKeyReleased(KEY_ENTER))
                    {
                        exit_window = true;
                    }
                    DrawText("BACK", screen_width / 2 - MeasureText("BACK", 20 * scale), 0.775 * GetScreenHeight(), 40, YELLOW);
                }
                else
                {
                    DrawText(highscores_options[i], screen_width / 2 - MeasureText(highscores_options[i], 20 * scale), 0.30 * screen_height, 40 * scale, YELLOW);
                    DrawText("BACK", screen_width / 2 - MeasureText("BACK", 20 * scale), 0.775 * GetScreenHeight(), 40, RAYWHITE);
                }
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            *select = 4;
            exit_window = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fx_select);
    //--------------------------------------------------------------------------------------
}