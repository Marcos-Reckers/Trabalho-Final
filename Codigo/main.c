#include <raylib.h>
#include "start.h"
#include "game.h"
#include "inputNames.h"
#include "highscores.h"
#include "credits.h"

// Main entry point
int main(void)
{
    // Initialization
    // -----------------------------------------------------
    int select = 0;
    int screen_width = 800;
    int screen_height = 600;

    // Enable config flags for resizable window and vertical synchro
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screen_width, screen_height, "BattleINF");
    SetWindowMinSize(600, 400);
    SetExitKey(0); // Remove Esc as an exit key
    InitAudioDevice();
    // -----------------------------------------------------

    do
    {
        start(&select);

        switch (select)
        {
        case 0:
        {
            game(&select);

            if (select == 0)
            {
                inputNames(&select);
                if (select == 0)
                {
                    highscores(&select);
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
            highscores(&select);
        }
        break;

        case 3:
        {
            credits(&select);
        }
        break;
        }

        if (WindowShouldClose())
        {
            select = 4;
        }

    } while (select != 4);

    CloseWindow();

    return 0;
}