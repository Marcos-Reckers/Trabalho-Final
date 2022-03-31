#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "credits.h"

// Main entry point
int credits(void){
    // Initialization
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int select = 0, frame = 0;
    int gitDir = -1, nomesDir = 1, backDir = -1; 
    int nomesMove = 0, backMove = 0, gitMove = 0.010 * screenHeight;
    bool exitWindow = false;

    SetTargetFPS(60);   // Set desired framerate (frames-per-second)

    Image tank = LoadImage("Assets/player_r.png");
    ImageResize(&tank, 30, 30);
    Texture2D tankTex = LoadTextureFromImage(tank);
    UnloadImage(tank);
    Image tankL = LoadImage("Assets/player_l.png");
    ImageResize(&tankL, 30, 30);
    Texture2D tankTexL = LoadTextureFromImage(tankL);
    UnloadImage(tankL);

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    Sound fxMove = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX4.wav");

    Rectangle infoRec = {0.250 * screenWidth, 0.250 * screenHeight, 0.500 * screenWidth, 0.500 * screenHeight};

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {   
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        frame++;
        frame %= 60;

        // --------------------------------------------------
        if (select == 2)
        {
            nomesDir = 1;
        }
        else
        {
            nomesDir = -1;
        }
        // --------------------------------------------------
        if (select == 2)
        {
            backDir = -1;
        }
        else
        {
            backDir = 1;
        }
        // --------------------------------------------------
        if (frame % 5 == 0)
        {
            gitMove += gitDir * 0.002 * screenHeight;
        }
        // --------------------------------------------------
        if ((select == 2 && nomesMove < 0.200 * screenHeight) || (select != 2 && nomesMove > 0))
        {
            nomesMove += nomesDir * 0.006 * screenHeight;
            if (frame % 10 == 0)
            {
                PlaySound(fxMove);
            }
        }
        // --------------------------------------------------
        if ((select == 2 && backMove > -0.200 * screenHeight) || (select != 2 && nomesMove > 0))
        {
            backMove += backDir * 0.006 * screenHeight;
            if (frame % 10 == 0)
            {
                PlaySound(fxMove);
            }
        }
        // --------------------------------------------------
        if (gitMove >= 0.010 * screenHeight || gitMove <= -0.010 * screenHeight)
        {
            gitDir = -gitDir;
        }
        // --------------------------------------------------

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select += 1;
            select %= 3; 
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fxSelect);
            select -= 1;
            if (select < 0)
            { 
                select = 3 - abs(select % 3);
            }
            else
            {
                select %= 3;
            }
        }

        if (select == 2)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                exitWindow = true; 
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);

            if (select != 2)
            {
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screenHeight + nomesMove, 2 * screenHeight / 30, RAYWHITE);
                DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screenHeight + nomesMove, 2 * screenHeight / 30, RAYWHITE);
                DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screenHeight + backMove, 2 * screenHeight / 30, RAYWHITE);
            }

            if (select == 0)
            {
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.050 * screenHeight + nomesMove, WHITE);
                DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.050 * screenHeight + nomesMove, WHITE);
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screenHeight + nomesMove, 2 * screenHeight / 30, YELLOW);
                if (nomesMove == 0 || nomesMove == -1)
                {
                    DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                    DrawText("github.com/Marcos-Reckers", screenWidth / 2 - MeasureText("github.com/Marcos-Reckers", GetFontDefault().baseSize), gitMove + 0.400 * screenHeight, screenHeight / 30, BLUE);
                    DrawText("00315653", screenWidth / 2 - MeasureText("00315653", GetFontDefault().baseSize) * 1.5, 0.500 * screenHeight, screenHeight / 20, BLUE);
                    DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screenHeight, screenHeight / 30, BLUE);
                }
            }
            if (select == 1)
            {
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.125 * screenHeight + nomesMove, WHITE);
                DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.125 * screenHeight + nomesMove, WHITE);
                DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screenHeight + nomesMove, 2 * screenHeight / 30, YELLOW);
                if (nomesMove == 0 || nomesMove == -1)
                {
                    DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                    DrawText("github.com/soupedroalmeida", screenWidth / 2 - MeasureText("github.com/soupedroalmeida", GetFontDefault().baseSize), gitMove + 0.400 * screenHeight, screenHeight / 30, BLUE);
                    DrawText("00333696", screenWidth / 2 - MeasureText("00333696", GetFontDefault().baseSize) * 1.5, 0.500 * screenHeight, screenHeight / 20, BLUE);
                    DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screenHeight, screenHeight / 30, BLUE);
                }
            }
            if (select == 2)
            {
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screenHeight + nomesMove, 2 * screenHeight / 30, RAYWHITE);
                DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screenHeight + nomesMove, 2 * screenHeight / 30, RAYWHITE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.850 * screenHeight + backMove, WHITE);
                DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Back", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.850 * screenHeight + backMove, WHITE);
                DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screenHeight + backMove, 2 * screenHeight / 30, YELLOW);
            }

        EndDrawing();

        if (WindowShouldClose())
        {
            select = 4;
            exitWindow = true;
        }
        if (IsKeyPressed(KEY_K))
        {
            printf("%d", nomesMove);
        }
    }

    UnloadSound(fxSelect);
    UnloadSound(fxMove);
    UnloadTexture(tankTex);

    return -1;   
}