#include <raylib.h>
#include "start.h"
#include "game.h"
#include "inputNames.h"
#include "highscores.h"
#include "credits.h"
#include "settings.h"

// Main entry point
int main(void)
{
    // Initialization
    // -----------------------------------------------------
    int screen_width = 1000;
    int screen_height = 650;
    cfg settings = {0};
    InitWindow(screen_width, screen_height, "BattleINF");
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

    do
    {
        start(&settings);

        switch (settings.select)
        {
        case 0:
        {
            game(&settings);

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
            // TODO: implementar tela de load
        }
        break;

        case 2:
        {
            highscores(&settings);
        }
        break;

        case 3:
        {
            credits(&settings);
        }
        break;
        }

        if (WindowShouldClose())
        {
            settings.select = 4;
        }

    } while (settings.select != 4);

    UnloadTexture(settings.right_tank);
    UnloadTexture(settings.left_tank);

    CloseWindow();

    return 0;
}