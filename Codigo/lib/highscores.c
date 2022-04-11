#include "raylib.h"
#include <stdlib.h>
#include "settings.h"

void highscores(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();
    settings->exit_window = false;
    settings->select = 0;
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    int displaynumber = 6;   // Display Number
    char options[4][100] =
        {// Option names
         "Rº\0",
         "Score\0",
         "Name\0",
         "Level\0"};

    char scoresdisplay[15][100] = // Array for the highscores
        {
            // score     name            level
            "4000\0", "Marcelo\0", "3\0",
            "8000\0", "Pedro\0", "5\0",
            "8800\0", "Felipe\0", "5\0",
            "19200\0", "Artur\0", "7\0",
            "46400\0", "Ian\0", "11\0"};
    //-----------------------------------------------------------------------

    // Main window loop
    //-----------------------------------------------------------------------
    while (!WindowShouldClose() && !settings->exit_window)
    {
        // Draw
        //--------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Highscores", screen_width / 2 - MeasureText("Highscores", 20), 0.050 * screen_height, 40, RAYWHITE);

        for (int i = 0; i < displaynumber; i++)
        {
            if (i == 0) // The first line is the titles for each row
            {
                DrawText(options[0], (GetScreenWidth() / 5) - MeasureText(options[0], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, GOLD);
                DrawText(options[1], (GetScreenWidth() / 5 * 2) - MeasureText(options[1], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, GREEN);
                DrawText(options[2], (GetScreenWidth() / 5 * 3) - MeasureText(options[2], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, VIOLET);
                DrawText(options[3], (GetScreenWidth() / 5 * 4) - MeasureText(options[3], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, BLUE);
            }
            else // After that, display the highscores in decreasing order
            {
                DrawText(TextFormat("%d", i), (GetScreenWidth() / 5) - MeasureText(TextFormat("%d", i), 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
                DrawText(scoresdisplay[12 - ((i - 1) * 3)], (GetScreenWidth() / 5 * 2) - MeasureText(scoresdisplay[12 - ((i - 1) * 3)], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
                DrawText(scoresdisplay[13 - ((i - 1) * 3)], (GetScreenWidth() / 5 * 3) - MeasureText(scoresdisplay[13 - ((i - 1) * 3)], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
                DrawText(scoresdisplay[14 - ((i - 1) * 3)], (GetScreenWidth() / 5 * 4) - MeasureText(scoresdisplay[14 - ((i - 1) * 3)], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            settings->select = 4;
            settings->exit_window = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(settings->fx_select);
    //--------------------------------------------------------------------------------------
}