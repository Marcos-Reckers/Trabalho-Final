#include "raylib.h"
#include <stdlib.h>
#include "settings.h"
#include "string.h"
#include "stdio.h"

void highscoresCrashFix2(void);
void highscores(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();
    double time = GetTime();
    settings->exit_window = false;
    settings->select = 0;
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    highscoresCrashFix2();

    int displaynumber = 6; // Display Number
    char options[3][100] =
        {// Option names
         "Rankingº\0",
         "Score\0",
         "Name\0"};

    HIGHSCORE scoresdisplay[5];                           // Array for the highscores
    FILE *highscores = fopen("bin/highscores.bin", "rb"); // Open the file

    // Read the file
    for (int i = 0; i < 5; i++)
    {
        fread(&scoresdisplay[i], sizeof(HIGHSCORE), 1, highscores);
    }
    fclose(highscores);
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
                DrawText(options[0], (GetScreenWidth() / 4) - MeasureText(options[0], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, GREEN);
                DrawText(options[1], (GetScreenWidth() / 4 * 2) - MeasureText(options[1], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, GREEN);
                DrawText(options[2], (GetScreenWidth() / 4 * 3) - MeasureText(options[2], 25) / 2, GetScreenHeight() / 4 + i * 50, 25, GREEN);
            }
            else // After that, display the highscores in decreasing order
            {
                DrawText(TextFormat("%d", i), (GetScreenWidth() / 4) - MeasureText(TextFormat("%d", i), 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
                DrawText(TextFormat("%s", scoresdisplay[i - 1].name), (GetScreenWidth() / 4 * 2) - MeasureText(TextFormat("%s", scoresdisplay[i - 1].name), 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
                DrawText(TextFormat("%d", scoresdisplay[i - 1].score), (GetScreenWidth() / 4 * 3) - MeasureText(TextFormat("%d", scoresdisplay[i - 1].score), 25) / 2, GetScreenHeight() / 4 + i * 50, 25, RAYWHITE);
            }
        }

        if (IsKeyReleased(KEY_ENTER) && GetTime() > time + 0.5)
        {
            PlaySound(settings->fx_select);
            WaitTime(200);
            settings->exit_window = true;
        }
        DrawTexture(settings->right_tank, GetScreenWidth() / 2 - MeasureText("BACK", 20) - 0.060 * screen_width, 0.77 * GetScreenHeight() + settings->right_tank.height / 4, WHITE);
        DrawText("BACK", screen_width / 2 - MeasureText("BACK", 20), 0.775 * GetScreenHeight(), 40, YELLOW);
        DrawTexture(settings->left_tank, GetScreenWidth() / 2 + MeasureText("BACK", 20) + 0.020 * screen_width, 0.77 * GetScreenHeight() + settings->left_tank.height / 4, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            settings->select = 5;
            settings->exit_window = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(settings->fx_select);
    //--------------------------------------------------------------------------------------
}

void highscoresCrashFix2(void)
{
    //! Highscores crash fix
    // If it doesn't find the highscores file, it will create it, avoids crashing
    if (!FileExists("bin/highscores.bin"))
    {
        FILE *noscores = fopen("bin/highscores.bin", "wb"); // Create highscores file
        HIGHSCORE scores[5] =                               // Creates a preselected array with madeup scores
            {
                {"AAA", 1},
                {"BBB", 2},
                {"CCC", 3},
                {"DDD", 4},
                {"EEE", 5},
            };
        fwrite(scores, sizeof(scores), 1, noscores); // Writes the madeup scores to the file
        fclose(noscores);                            // Close the file
    }
}