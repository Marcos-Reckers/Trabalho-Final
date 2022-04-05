#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


int highscores(void)
{
    // Initialization
    int framesCounter = 0;
    int select = 0;
    int backMove = 0;
    bool exitWindow = false;
    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main game loop
    while (!WindowShouldClose() && !exitWindow)    // Detect window close button or ESC key
    {
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        float scale = (screenHeight * screenWidth) / (600.0 * 800.0);

        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        if (select == 2)
        {
            backMove += 0.006 * screenHeight;
            if (framesCounter % 10 == 0)
            {
                PlaySound(fxSelect);
            }
        }

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select += 1;
            select %= 4; 
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fxSelect);
            select -= 1;
            if (select < 0)
            { 
                select = 4 - abs(select % 4);
            }
            else
            {
                select %= 4;
            }
        }
    
        framesCounter++;

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawText("Back", screenWidth / 2 - MeasureText("Back", 20 * scale), 0.850 * screenHeight, 40 * scale, RAYWHITE);

            if (select == 0)
            {
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", 20 * scale), 0.050 * screenHeight, 40 * scale, YELLOW);
            }

            if (select == 3){
                DrawText("Lucas de Oliveira", screenWidth / 2 - MeasureText("Lucas de Oliveira", 20 * scale), 0.050 * screenHeight, 40 * scale, YELLOW);
            }
        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            select = 0;
            exitWindow = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxSelect);
    //--------------------------------------------------------------------------------------
    return select;
}