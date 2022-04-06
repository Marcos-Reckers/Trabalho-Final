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
    int screen_width = 800;
    int screen_height = 600;
    cfg settings = {0};

    // Enable config flags for resizable window and vertical synchro
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, "BattleINF");
    SetWindowMinSize(600, 400);
    SetTargetFPS(60);
    SetExitKey(0); // Remove Esc as an exit key
    InitAudioDevice();
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

    CloseWindow();

    return 0;
}