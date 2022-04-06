#include "raylib.h"
#include "pause.h"

void Game(int *select)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int frames_counter = 0;
    bool exit_window = false;
    bool pause = false;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exit_window && !WindowShouldClose())
    {

        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_ESCAPE))
        {
            pause = true;
        }

        if (!pause)
        {
            if (IsKeyReleased(KEY_ENTER))
            {
                WaitTime(200);
                break;
            }
        }
        else
        {
            frames_counter++;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Hello World!", 100, 100, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            *select = 4;
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------
}