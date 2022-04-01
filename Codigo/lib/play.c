#include "raylib.h"
#include <stdio.h>
#include "object.h"
#include "player_1.h"
#include "DrawFunctions.h"

int play(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------
    int framesCounter = 0;
    int select = 0;
    bool pause = 0;
    bool exitWindow = false;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // OBJECTS
    //--------------------------------------------------------------------------------------
    OBJECT player_1 = MakeObject(
        "Assets/player.png",
        (Rectangle){100, 100, (0.075 * GetScreenWidth()), (0.075 * GetScreenWidth())}, // body
        (Vector2){(0.075 * GetScreenWidth()) / 2, (0.075 * GetScreenHeight()) / 2},    // origin
        3.0                                                                            // speed
    );

    //--------------------------------------------------------------------------------------

    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
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
            framesCounter++;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawOBJECT(player_1.texture, player_1);

        select = DrawPause(pause, framesCounter, select);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
        if (IsKeyReleased(KEY_ENTER))
        {
            pause = false;
        }

        if (select && !pause)
        {
            exitWindow = true;
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