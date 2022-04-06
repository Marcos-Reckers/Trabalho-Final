#include "raylib.h"
#include <stdio.h>
#include "object.h"
#include "player_1.h"
#include "DrawFunctions.h"

int play(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------
    int frames_counter = 0;
    int select = 0;
    bool pause = 0;
    bool exit_window = false;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // OBJECTS
    //--------------------------------------------------------------------------------------
    OBJECT player_1 = MakeObject(
        "Assets/player.png",
        (Rectangle){100, 100, (0.075 * GetscreenWidth()), (0.075 * GetscreenWidth())}, // body
        (Vector2){(0.075 * GetscreenWidth()) / 2, (0.075 * GetScreenHeight()) / 2},    // origin
        3.0                                                                            // speed
    );

    //--------------------------------------------------------------------------------------

    while (!exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ESCAPE))
            pause = true;

        if (!pause)
        {
            UpdatePlayer_1(player_1);
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

        DrawOBJECT(player_1.texture, player_1);

        select = DrawPause(pause, frames_counter, select);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
        if (IsKeyReleased(KEY_ENTER))
        {
            pause = false;
        }

        if (select && !pause)
        {
            exit_window = true;
        }

        if (WindowShouldClose())
        {
            select = 4;
            break;
        }
    }

    // Menu-Integration
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------

    // De-Initialization
    //----------------------------------------------------------------------------------
    UnloadTexture(player_1.texture);
    //----------------------------------------------------------------------------------

    return select;
}