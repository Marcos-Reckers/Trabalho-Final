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
    settings->select = 0;
    Rectangle credits_rectangle = {GetScreenWidth()/2 - 350 / 2 , GetScreenHeight() / 2 - 90 / 2, 350, 100};

    // Movement variables
    int increment_options[NUM_OPTIONS] = {0, 0, 0};
    int movement_speed = 3;

    SetTargetFPS(60); // Set desired framerate (frames-per-second)

    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        frames_counter++;
        frames_counter %= 60;

        int screen_width = GetScreenWidth();
        int screen_height = GetScreenHeight();

        if (credits_select == 2 && increment_options[0] < 60)
        {
            increment_options[0] += movement_speed;
            increment_options[1] += movement_speed;
            increment_options[2] -= movement_speed;
        }
        if (credits_select != 2 && increment_options[0] > 0)
        {
            increment_options[0] -= movement_speed;
            increment_options[1] -= movement_speed;
            increment_options[2] += movement_speed;
        }

        // Updated height of the options
        int options_height[NUM_OPTIONS] = 
        {
            (0.15 * screen_height + increment_options[0]),
            (0.15 * screen_height + 50 + increment_options[1]),
            (0.75 * screen_height + increment_options[2])
        };

        // Move between options
        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(settings->fx_select);
            credits_select += 1;
            credits_select %= 3;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(settings->fx_select);
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

        // Back case
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
                    DrawTexture(settings->right_tank, screen_width / 2 - MeasureText(credits_options[option], 20) - 0.060 * screen_width, options_height[option], WHITE);
                    DrawText(credits_options[option], screen_width / 2 - MeasureText(credits_options[option], 20), options_height[option], 40, YELLOW);
                    DrawTexture(settings->left_tank, screen_width / 2 + MeasureText(credits_options[option], 20) + 0.020 * screen_width, options_height[option], WHITE);
                }
                else
                {
                    DrawText(credits_options[option], screen_width / 2 - MeasureText(credits_options[option], 20), options_height[option], 40, RAYWHITE);
                }
            }

            if (credits_select != 2)
            {
                DrawRectangleLinesEx(credits_rectangle, 4, BLUE);
                DrawText("05/2022", screen_width / 2 - MeasureText("05/2022", 10), screen_height / 2 - 20, 20, BLUE);
            }
            if (credits_select == 1)
            {
                DrawText("github.com/soupedroalmeida", screen_width / 2 - MeasureText("github.com/soupedroalmeida", 10), screen_height / 2, 20, BLUE);
                DrawText("Cartão - 333696", screen_width / 2 - MeasureText("Cartão - 333696", 10), screen_height / 2 + 20, 20, BLUE);
            }
            if (credits_select == 0)
            {
                DrawText("github.com/Marcos-Reckers", screen_width / 2 - MeasureText("github.com/Marcos-Reckers", 10), screen_height / 2, 20, BLUE);
                DrawText("Cartão - 315653", screen_width / 2 - MeasureText("Cartão - 315653", 10), screen_height / 2 + 20, 20, BLUE);
            }

            

        EndDrawing();

        if (WindowShouldClose())
        {
            settings->select = 4;
            settings->exit_window = true;
        }
    }

    UnloadSound(settings->fx_select);
}