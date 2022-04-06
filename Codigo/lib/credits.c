#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "credits.h"
#include "settings.h"

#define NUM_OPTIONS 3


void credits(cfg *settings)
{
    // Initialization
    int credits_select = 0;
    char credits_options[NUM_OPTIONS][50] = {"Marcos Luiz Kurth Reckers\0", "Pedro Henrique Almeida de Paula\0", "Back\0"};
    int frames_counter = 0;
    settings->exit_window = false;

    // Movement variables
    int increment_options[NUM_OPTIONS] = {0, 0, 0};
    int state_options = 0;
    int movement_speed = 2;

    SetTargetFPS(60); // Set desired framerate (frames-per-second)

    Image right_tank_im = LoadImage("Assets/player_r.png");
    ImageResize(&right_tank_im, 30, 30);
    Texture2D right_tank = LoadTextureFromImage(right_tank_im);
    UnloadImage(right_tank_im);

    Image left_tank_im = LoadImage("Assets/player_l.png");
    ImageResize(&left_tank_im, 30, 30);
    Texture2D left_tank = LoadTextureFromImage(left_tank_im);
    UnloadImage(left_tank_im);

    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        frames_counter++;
        frames_counter %= 60;

        int screen_width = GetScreenWidth();
        int screen_height = GetScreenHeight();
        float scale = (screen_height * screen_width) / (600.0 * 800.0);

        if (state_options == 0)
        {
            increment_options[0] += movement_speed * scale;
            if (increment_options[0] >= 60* scale)
            {
                state_options = 1;
            }
            increment_options[1] += movement_speed * scale;
            increment_options[2] -= movement_speed * scale;
        }
        if (state_options == 1)
        {
            increment_options[0] -= movement_speed * scale;
            if (increment_options[0] <= 0)
            {
                state_options = 0;
            }
            increment_options[1] -= movement_speed * scale;
            increment_options[2] += movement_speed * scale;
        }

        int options_height[NUM_OPTIONS] = {(0.10 * screen_height + increment_options[0]),
                                           (0.10 * screen_height + 50 * scale + increment_options[1]),
                                           (0.85 * screen_height + increment_options[2])};

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fx_select);
            credits_select += 1;
            credits_select %= 3;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fx_select);
            credits_select -= 1;
            if (credits_select < 0)
            {
                credits_select = 3 - abs(credits_select % 3);
            }
            else
            {
                credits_select %= 3;
            }
        }

        if (credits_select == 2 && IsKeyReleased(KEY_ENTER))
        {
            settings->exit_window = true;
        }

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);

            for (int option = 0; option < NUM_OPTIONS; option++)
            {
                if (option == credits_select)
                {
                    DrawTexture(right_tank, screen_width / 2 - MeasureText(credits_options[option], 20 * scale) - 0.060 * screen_width, options_height[option], WHITE);
                    DrawText(credits_options[option], screen_width / 2 - MeasureText(credits_options[option], 20 * scale), options_height[option], 40 * scale, YELLOW);
                    DrawTexture(left_tank, screen_width / 2 + MeasureText(credits_options[option], 20 * scale) + 0.020 * screen_width, options_height[option], WHITE);
                }
                else
                {
                    DrawText(credits_options[option], screen_width / 2 - MeasureText(credits_options[option], 20 * scale), options_height[option], 40 * scale, RAYWHITE);
                }
            }

        EndDrawing();

        if (WindowShouldClose())
        {
            settings->select = 4;
            settings->exit_window = true;
        }
    }

    UnloadSound(fx_select);
}