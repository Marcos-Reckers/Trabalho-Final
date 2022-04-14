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
    cfg settings = {0};
    setup(&settings);

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