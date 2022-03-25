#include "raylib.h"
#include <stdio.h>
#include "object.h"
#include "screen.h"
#include "player_1.h"
#include "DrawFunctions.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int framesCounter = 0;
    int select = 0;
    bool pause = 0;
    bool exitWindow = false;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    OBJECT player_1 = MakeObject(
        "Assets/player_u.png",
        (Rectangle){GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()), (0.075 * GetScreenWidth()), (0.075 * GetScreenWidth())}, // body
        (Vector2){(0.075 * GetScreenWidth()) / 2, (0.075 * GetScreenWidth()) / 2},                                                                      // origin
        3.0                                                                                                                                             // speed
    );

    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_P))
            pause = !pause;

        if (!pause)
        {
            player_1 = UpdatePlayer_1(player_1);
        }
        else
            framesCounter++;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawOBJECT(player_1.texture, player_1);

        DrawPause(pause, framesCounter);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Menu-Integration
    //----------------------------------------------------------------------------------
    if (WindowShouldClose())
    {
        select = 4;
        exitWindow = true;
    }
    //----------------------------------------------------------------------------------

    // De-Initialization
    //----------------------------------------------------------------------------------
    UnloadTexture(player_1.texture);
    //----------------------------------------------------------------------------------

    return 0;
}