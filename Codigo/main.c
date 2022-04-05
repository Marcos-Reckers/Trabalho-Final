#include <raylib.h>
#include "credits.h"
#include "start.h"
#include "highscores.h"
#include "inputNames.h"

// Main entry point
int main(void)
{
    // Initialization
    int select;
    int screenWidth = 800;
    int screenHeight = 600;

    // Enable config flags for resizable window and vertical synchro
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "BattleINF");
    SetWindowMinSize(600, 400);
    SetExitKey(0); // Remove Esc as an exit key
    InitAudioDevice();

    do
    {
        select = start();

        switch (select)
        {
        case 0:
        {
            // select = play();
            if (select == 0)
            {
                select = inputNames();
                if (select == 0)
                {
                    select = highscores();
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
            select = highscores();
        }
        break;

        case 3:
        {
            select = credits();
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