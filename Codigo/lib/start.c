#include <raylib.h>
#include <stdlib.h>
#include "settings.h"

// Main entry point
void start(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    char start_options[5][50] = {"Play\0", "Load\0", "Highscores\0", "Credits\0", "Exit\0"};
    settings->exit_window = false;

    Image logo = LoadImage("Assets/battleinflogo.png");
    Image tank = LoadImage("Assets/player_r.png");
    Image tankL = LoadImage("Assets/player_l.png");
    ImageResize(&logo, (0.800 * GetScreenWidth()), (0.190 * GetScreenHeight()));
    ImageResize(&tank, (0.035 * GetScreenWidth()), (0.050 * GetScreenHeight()));
    ImageResize(&tankL, (0.035 * GetScreenWidth()), (0.050 * GetScreenHeight()));
    Texture2D logoTex = LoadTextureFromImage(logo);
    Texture2D tankTex = LoadTextureFromImage(tank);
    Texture2D tankTexL = LoadTextureFromImage(tankL);
    UnloadImage(logo);
    UnloadImage(tank);
    UnloadImage(tankL);

    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main window loop
    while (!settings->exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        int screen_width = GetScreenWidth();
        int screen_height = GetScreenHeight();
        float scale = (screen_height * screen_width) / (600.0 * 800.0);

        // Navigation on TITLE menu

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fx_select);
            settings->select += 1;
            settings->select %= 5; // Transform select into a value between 0 and 3
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fx_select);
            settings->select -= 1;

            if (settings->select < 0) // If select is negative, go to the maximum possible value: 3
            {
                settings->select = 5 - abs(settings->select % 5);
            }
            else
            {
                settings->select %= 5;
            }
        }

        // Depending on select value and if enter is pressed, change the screen

        if (IsKeyReleased(KEY_ENTER))
        {
            PlaySound(fx_select);
            WaitTime(90);
            settings->exit_window = true;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(logoTex, screen_width / 2 - logoTex.width / 2, 0.150 * screen_height, WHITE);

        for (int i = 0; i < 5; i++)
        {
            if (i == settings->select)
            {
                DrawTexture(tankTex, screen_width / 2 - MeasureText(start_options[i], 20 * scale) - 0.060 * screen_width, 0.40 * screen_height + (75 * i) + tankTex.height / 4, WHITE);
                DrawText(start_options[i], screen_width / 2 - MeasureText(start_options[i], 20 * scale), 0.40 * screen_height + (75 * i), 40 * scale, YELLOW);
                DrawTexture(tankTexL, screen_width / 2 + MeasureText(start_options[i], 20 * scale) + 0.020 * screen_width, 0.40 * screen_height + (75 * i) + tankTexL.height / 4, WHITE);
            }
            else
            {
                DrawText(start_options[i], screen_width / 2 - MeasureText(start_options[i], 20 * scale), 0.40 * screen_height + (75 * i), 40 * scale, RAYWHITE);
            }
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            settings->select = 4;
            settings->exit_window = true;
        }
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(logoTex);
    UnloadTexture(tankTex);
    UnloadTexture(tankTexL);
    UnloadSound(fx_select);
    //--------------------------------------------------------------------------------------
}