#include <raylib.h>
#include "start.h"
#include "game.h"
#include "inputNames.h"
#include "highscores.h"
#include "credits.h"
#include "settings.h"
#include <stdio.h>
#include "load.h"

// Main entry point
int main(void)
{
    // Initialization
    // -----------------------------------------------------
    int screen_width = 1000;
    int screen_height = 650;
    cfg settings = {0};
    InitWindow(screen_width, screen_height, "BattleINF");
    SetWindowIcon(LoadImage("Assets/player_r.png"));
    SetWindowTitle("BattleINF");
    SetTargetFPS(60);
    SetExitKey(0); // Remove Esc as an exit key
    InitAudioDevice();

    // Load assets textures
    Image right_tank_im = LoadImage("Assets/player_r.png");
    ImageResize(&right_tank_im, 30, 30);
    settings.right_tank = LoadTextureFromImage(right_tank_im);
    UnloadImage(right_tank_im);

    Image left_tank_im = LoadImage("Assets/player_l.png");
    ImageResize(&left_tank_im, 30, 30);
    settings.left_tank = LoadTextureFromImage(left_tank_im);
    UnloadImage(left_tank_im);
    // -----------------------------------------------------
    settings.save_game = false;

    do
    {
        start(&settings);

        switch (settings.select)
        {
        case 0:
        {
            settings.level = 1;
            settings.player_score = 0;
            do
            {
                game(&settings);
                settings.level++;
            } while (settings.player_lives > 0 && settings.level < 5 && settings.select == 0);

            if (settings.select == 0)
            {
                inputNames(&settings);
                if (settings.select == 0)
                {
                    highscores(&settings);
                }
            }
        }
        break;

        case 1:
        {
            FILE *file = fopen("bin/save.bin", "rb");
            if (file != NULL)
            {
                fread(&settings, sizeof(settings), 1, file);
                fclose(file);
                settings.save_game = true;
                do
                {
                    game(&settings);
                    settings.save_game = false;
                    settings.level++;
                } while (settings.player_lives > 0 && settings.level < 5 && settings.select == 0);

                if (settings.select == 0)
                {
                    inputNames(&settings);
                    if (settings.select == 0)
                    {
                        highscores(&settings);
                    }
                }
            }
        }
        break;

        case 2:
            load(&settings);
            break;

        case 3:
        {
            highscores(&settings);
        }
        break;

        case 4:
        {
            credits(&settings);
        }
        break;
        }

        if (WindowShouldClose())
        {
            settings.select = 5;
        }

    } while (settings.select != 5);

    UnloadTexture(settings.right_tank);
    UnloadTexture(settings.left_tank);

    CloseWindow();

    return 0;
}