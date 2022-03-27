#include <raylib.h>
#include <stdlib.h>
#include "credits.h"

// Main entry point
int credits(void){
    // Initialization
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int select = 0, gitMove = -0.010 * screenHeight, direction = 1, frame = 0;
    bool exitWindow = false;

    SetTargetFPS(60);   // Set desired framerate (frames-per-second)

    Image tank = LoadImage("Assets/player_r.png");
    ImageResize(&tank, 30, 30);
    Texture2D tankTex = LoadTextureFromImage(tank);
    UnloadImage(tank);

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    Rectangle infoRec = {0.250 * screenWidth, 0.250 * screenHeight, 0.500 * screenWidth, 0.500 * screenHeight};

    // Main game loop
    while (!exitWindow && !WindowShouldClose()){   // Detect window close button or ESC key
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        frame++;
        frame %= 60;

        if (frame % 5 == 0){
            gitMove += direction * 0.002 * screenHeight;
        }
        if (gitMove >= 0.010 * screenHeight){
            direction = -1;
        }
        if (gitMove <= -0.010 * screenHeight){
            direction = 1;
        }

        if (IsKeyPressed(KEY_DOWN)){
            PlaySound(fxSelect);
            select += 1;
            select %= 3; 
        }
        else if (IsKeyPressed(KEY_UP)){
            PlaySound(fxSelect);
            select -= 1;
            if (select < 0){ 
                select = 3 - abs(select % 3);
            }
            else{
                select %= 3;
            }
        }

        if (select == 2){
            if (IsKeyPressed(KEY_ENTER)){
                exitWindow = true; 
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);

            DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screenHeight, 2 * screenHeight / 30, RAYWHITE);
            DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screenHeight, 2 * screenHeight / 30, RAYWHITE);
            DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screenHeight, 2 * screenHeight / 30, RAYWHITE);

            if (select == 0){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 - 50, 0.050 * screenHeight, WHITE);
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, 0.050 * screenHeight, 2 * screenHeight / 30, YELLOW);
                DrawText("github.com/Marcos-Reckers", screenWidth / 2 - MeasureText("github.com/Marcos-Reckers", GetFontDefault().baseSize), gitMove + 0.400 * screenHeight, 20, BLUE);
                DrawText("00315653", screenWidth / 2 - MeasureText("00315653", GetFontDefault().baseSize) * 1.5, 0.500 * screenHeight, 30, BLUE);
                DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screenHeight, 20, BLUE);
            }
            if (select == 1){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 - 50, 0.125 * screenHeight, WHITE);
                DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, 0.125 * screenHeight, 2 * screenHeight / 30, YELLOW);
                DrawText("github.com/soupedroalmeida", screenWidth / 2 - MeasureText("github.com/soupedroalmeida", GetFontDefault().baseSize), gitMove + 0.400 * screenHeight, 20, BLUE);
                DrawText("00333696", screenWidth / 2 - MeasureText("00333696", GetFontDefault().baseSize) * 1.5, 0.500 * screenHeight, 30, BLUE);
                DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), 0.550 * screenHeight, 20, BLUE);
            }
            if (select == 2){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2 - 50, 0.850 * screenHeight, WHITE);
                DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 0.850 * screenHeight, 2 * screenHeight / 30, YELLOW);
                DrawText(".", screenWidth / 2 - MeasureText(".", GetFontDefault().baseSize) * 1.5, screenHeight / 2, 30, BLUE);
            }

        EndDrawing();

        if (WindowShouldClose()){
            select = 4;
           exitWindow = true;
        }
    }

    UnloadSound(fxSelect);
    UnloadTexture(tankTex);

    return -1;
}