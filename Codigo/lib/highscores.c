#include "raylib.h"
#include <stdlib.h>

int highscores(void)
{
    // Initialization
    // -----------------------------------------------------
    int framesCounter = 0;
    int select = 0;
    char options[5][50] = {"Marcos\0", "Pedro\0", "player 2\0", "player 3\0", "player 4\0"};
    bool exitWindow = false;
    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    //-----------------------------------------------------------------------

    // Main window loop
    //-----------------------------------------------------------------------
    while (!WindowShouldClose() && !exitWindow)
    {
        // Update
        //----------------------------------------------------------------------------------
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        float scale = (screenHeight * screenWidth) / (600.0 * 800.0);

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select += 1;
            select %= 6;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fxSelect);
            select -= 1;
            if (select < 0)
            {
                select = 6 - abs(select % 6);
            }
            else
            {
                select %= 6;
            }
        }

        framesCounter++;
        //--------------------------------------------------------------------

        // Draw
        //--------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Highscores", screenWidth / 2 - MeasureText("Highscores", 20 * scale), 0.050 * screenHeight, 40 * scale, RAYWHITE);

        for (int i = 0; i < 6; i++)
        {
            if (i == select)
            {
                if (select == 5)
                {
                    if (IsKeyReleased(KEY_ENTER))
                    {
                        select = 0;
                        exitWindow = true;
                    }
                    DrawText("BACK", screenWidth / 2 - MeasureText("BACK", 20 * scale), 0.775 * GetScreenHeight(), 40, YELLOW);
                }
                else
                {
                    DrawText(options[i], screenWidth / 2 - MeasureText(options[i], 20 * scale), 0.30 * screenHeight, 40 * scale, YELLOW);
                    DrawText("BACK", screenWidth / 2 - MeasureText("BACK", 20 * scale), 0.775 * GetScreenHeight(), 40, RAYWHITE);
                }
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            select = 4;
            exitWindow = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxSelect);
    //--------------------------------------------------------------------------------------
    return select;
}