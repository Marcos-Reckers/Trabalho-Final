#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "credits.h"

// Main entry point
void Credits(int *select)
{
    // Initialization
    int screen_width = GetscreenWidth();
    int screen_height = GetScreenHeight();
    int frame = 0;
    int gitDir = -1;
    int nomesDir = 1;
    int backDir = -1;
    int nomesMove = 0;
    int backMove = 0;
    int gitMove = 0.010 * screen_height;
    bool exit_window = false;

    SetTargetFPS(60); // Set desired framerate (frames-per-second)

    Image tank = LoadImage("Assets/player_r.png");
    ImageResize(&tank, 30, 30);
    Texture2D tankTex = LoadTextureFromImage(tank);
    UnloadImage(tank);
    Image tankL = LoadImage("Assets/player_l.png");
    ImageResize(&tankL, 30, 30);
    Texture2D tankTexL = LoadTextureFromImage(tankL);
    UnloadImage(tankL);

    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    Sound fxMove = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX4.wav");

    Rectangle infoRec = {0.250 * screen_width, 0.250 * screen_height, 0.500 * screen_width, 0.500 * screen_height};

    // Main game loop
    while (!exit_window && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Navigation on TITLE menu
        frame++;
        frame %= 60;

        // --------------------------------------------------
        if (*select == 2)
        {
            nomesDir = 1;
        }
        else
        {
            nomesDir = -1;
        }
        // --------------------------------------------------
        if (*select == 2)
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
            gitMove += gitDir * 0.002 * screen_height;
        }
        // --------------------------------------------------
        if ((*select == 2 && nomesMove < 0.200 * screen_height) || (*select != 2 && nomesMove > 0))
        {
            nomesMove += nomesDir * 0.006 * screen_height;
            if (frame % 10 == 0)
            {
                PlaySound(fxMove);
            }
        }
        // --------------------------------------------------
        if ((*select == 2 && backMove > -0.200 * screen_height) || (*select != 2 && nomesMove > 0))
        {
            backMove += backDir * 0.006 * screen_height;
            if (frame % 10 == 0)
            {
                PlaySound(fxMove);
            }
        }
        // --------------------------------------------------
        if (gitMove >= 0.010 * screen_height || gitMove <= -0.010 * screen_height)
        {
            gitDir = -gitDir;
        }
        // --------------------------------------------------

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fx_select);
            *select += 1;
            *select %= 3;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fx_select);
            *select -= 1;
            if (*select < 0)
            {
                *select = 3 - abs(*select % 3);
            }
            else
            {
                *select %= 3;
            }
        }

        if (*select == 2)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                exit_window = true;
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        if (*select != 2)
        {
            DrawText("Marcos Luiz Kurth Reckers", screen_width / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screen_height + nomesMove, 2 * screen_height / 30, RAYWHITE);
            DrawText("Pedro Henrique Almeida de Paula", screen_width / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screen_height + nomesMove, 2 * screen_height / 30, RAYWHITE);
            DrawText("Back", screen_width / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screen_height + backMove, 2 * screen_height / 30, RAYWHITE);
        }

        if (*select == 0)
        {
            DrawTexture(tankTex, screen_width / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 - 0.060 * screen_width, 0.050 * screen_height + nomesMove, WHITE);
            DrawTexture(tankTexL, screen_width / 2 + MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 + 0.020 * screen_width, 0.050 * screen_height + nomesMove, WHITE);
            DrawText("Marcos Luiz Kurth Reckers", screen_width / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screen_height + nomesMove, 2 * screen_height / 30, YELLOW);
            if (nomesMove == 0 || nomesMove == -1)
            {
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawText("github.com/Marcos-Reckers", screen_width / 2 - MeasureText("github.com/Marcos-Reckers", GetFontDefault().baseSize), gitMove + 0.400 * screen_height, screen_height / 30, BLUE);
                DrawText("00315653", screen_width / 2 - MeasureText("00315653", GetFontDefault().baseSize) * 1.5, 0.500 * screen_height, screen_height / 20, BLUE);
                DrawText("05/2022", screen_width / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screen_height, screen_height / 30, BLUE);
            }
        }
        if (*select == 1)
        {
            DrawTexture(tankTex, screen_width / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 - 0.060 * screen_width, 0.125 * screen_height + nomesMove, WHITE);
            DrawTexture(tankTexL, screen_width / 2 + MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 + 0.020 * screen_width, 0.125 * screen_height + nomesMove, WHITE);
            DrawText("Pedro Henrique Almeida de Paula", screen_width / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screen_height + nomesMove, 2 * screen_height / 30, YELLOW);
            if (nomesMove == 0 || nomesMove == -1)
            {
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawText("github.com/soupedroalmeida", screen_width / 2 - MeasureText("github.com/soupedroalmeida", GetFontDefault().baseSize), gitMove + 0.400 * screen_height, screen_height / 30, BLUE);
                DrawText("00333696", screen_width / 2 - MeasureText("00333696", GetFontDefault().baseSize) * 1.5, 0.500 * screen_height, screen_height / 20, BLUE);
                DrawText("05/2022", screen_width / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screen_height, screen_height / 30, BLUE);
            }
        }
        if (*select == 2)
        {
            DrawText("Marcos Luiz Kurth Reckers", screen_width / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screen_height + nomesMove, 2 * screen_height / 30, RAYWHITE);
            DrawText("Pedro Henrique Almeida de Paula", screen_width / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screen_height + nomesMove, 2 * screen_height / 30, RAYWHITE);
            DrawTexture(tankTex, screen_width / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2 - 0.060 * screen_width, 0.850 * screen_height + backMove, WHITE);
            DrawTexture(tankTexL, screen_width / 2 + MeasureText("Back", GetFontDefault().baseSize) * 2 + 0.020 * screen_width, 0.850 * screen_height + backMove, WHITE);
            DrawText("Back", screen_width / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screen_height + backMove, 2 * screen_height / 30, YELLOW);
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            *select = 4;
            exit_window = true;
        }
        if (IsKeyPressed(KEY_K))
        {
            printf("%d", nomesMove);
        }
    }

    UnloadSound(fx_select);
    UnloadSound(fxMove);
    UnloadTexture(tankTex);
}