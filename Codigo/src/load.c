#include <raylib.h>
#include <stdlib.h>
#include "settings.h"
#include "game.h"
#include <string.h>
#include "highscores.h"

// Main entry point
void load(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    char load_options[6][50] = {"level 1\0", "level 2\0", "level 3\0", "level 4\0", "level 5\0", "Exit\0"};
    settings->exit_window = false;
    settings->select = 0;

    Image logo = LoadImage("Assets/battleinflogo.png");
    ImageResize(&logo, (0.800 * GetScreenWidth()), (0.190 * GetScreenHeight()));
    Texture2D logoTex = LoadTextureFromImage(logo);
    UnloadImage(logo);

    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    settings->player_score = 0;

    // Main window loop
    while (!settings->exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        int screen_width = GetScreenWidth();
        int screen_height = GetScreenHeight();

        // Navigation on TITLE menu

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(settings->fx_select);
            settings->select += 1;
            settings->select %= 6; // Transform select into a value between 0 and 3
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(settings->fx_select);
            settings->select -= 1;

            if (settings->select < 0) // If select is negative, go to the maximum possible value: 3
            {
                settings->select = 6 - abs(settings->select % 6);
            }
            else
            {
                settings->select %= 6;
            }
        }

        // Depending on select value and if enter is pressed, change the screen

        if (IsKeyReleased(KEY_ENTER))
        {
            PlaySound(settings->fx_select);
            WaitTime(90);
            if (settings->select != 5)
            {
                settings->level = settings->select + 1;
                do
                {
                    game(settings);
                    settings->level++;
                } while (settings->player_lives > 0 && settings->level < 5 && settings->select == 0);

                if (settings->select == 0)
                {
                    highscores(settings);
                }

                break;
            }
            else
            {
                settings->select = 0;
                settings->exit_window = true;
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(logoTex, screen_width / 2 - logoTex.width / 2, 0.080 * screen_height, WHITE);

        for (int i = 0; i < 6; i++)
        {
            if (i == settings->select)
            {
                DrawTexture(settings->right_tank, screen_width / 2 - MeasureText(load_options[i], 20) - 0.060 * screen_width, 0.3 * screen_height + (75 * i) + settings->right_tank.height / 4, WHITE);
                DrawText(load_options[i], screen_width / 2 - MeasureText(load_options[i], 20), 0.3 * screen_height + (75 * i), 40, YELLOW);
                DrawTexture(settings->left_tank, screen_width / 2 + MeasureText(load_options[i], 20) + 0.020 * screen_width, 0.3 * screen_height + (75 * i) + settings->left_tank.height / 4, WHITE);
            }
            else
            {
                DrawText(load_options[i], screen_width / 2 - MeasureText(load_options[i], 20), 0.3 * screen_height + (75 * i), 40, RAYWHITE);
            }
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            settings->select = 5;
            settings->exit_window = true;
        }
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(logoTex);
    //--------------------------------------------------------------------------------------
}