#include <raylib.h>
#include <stdlib.h>
#include "credits.h"

// Main entry point
void credits(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int select = 0, loadMove = 0;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    InitAudioDevice();

    SetTargetFPS(60);   // Set desired framerate (frames-per-second)

    Image tank = LoadImage("Assets/player_r.png");
    ImageResize(&tank, 30, 30);
    Texture2D tankTex = LoadTextureFromImage(tank);
    UnloadImage(tank);

    Sound fxSelect = LoadSound("Assets\\NES - Battle City JPN - Sound Effects\\Battle City SFX (5).wav");

    Rectangle infoRec = {screenWidth / 4 , screenHeight / 4 + 20, screenWidth / 2, screenHeight / 2};

    // Main game loop
    while (!WindowShouldClose()){   // Detect window close button or ESC key
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        loadMove++;

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
                // Open start.c
            }
        }
        

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);

            DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, screenHeight / 20 + 40, 40, RAYWHITE);
            DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, screenHeight / 20, 40, RAYWHITE);
            DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 17 * screenHeight / 20, 40, RAYWHITE);

            if (select == 0){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2 - 50, screenHeight / 20 + 5, WHITE);
                DrawText("Marcos Luiz Kurth Reckers", screenWidth / 2 - MeasureText("Marcos Luiz Kurth Reckers", GetFontDefault().baseSize) * 2, screenHeight / 20, 40, YELLOW);
                DrawText("github.com/Marcos-Reckers", screenWidth / 2 - MeasureText("github.com/Marcos-Reckers", GetFontDefault().baseSize), screenHeight / 2 - 30, 20, BLUE);
                DrawText("00315653", screenWidth / 2 - MeasureText("00315653", GetFontDefault().baseSize) * 1.5, screenHeight / 2, 30, BLUE);
                DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), screenHeight / 2 + 40, 20, BLUE);
            }
            if (select == 1){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2 - 50, screenHeight / 20 + 45, WHITE);
                DrawText("Pedro Henrique Almeida de Paula", screenWidth / 2 - MeasureText("Pedro Henrique Almeida de Paula", GetFontDefault().baseSize) * 2, screenHeight / 20 + 40, 40, YELLOW);
                DrawText("github.com/soupedroalmeida", screenWidth / 2 - MeasureText("github.com/soupedroalmeida", GetFontDefault().baseSize), screenHeight / 2 - 30, 20, BLUE);
                DrawText("00333696", screenWidth / 2 - MeasureText("00333696", GetFontDefault().baseSize) * 1.5, screenHeight / 2, 30, BLUE);
                DrawText("05/2022", screenWidth / 2 - MeasureText("05/2022", GetFontDefault().baseSize), screenHeight / 2 + 40, 20, BLUE);
            }
            if (select == 2){
                DrawRectangleLinesEx(infoRec, 4.0, BLUE);
                DrawTexture(tankTex, screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2 - 50, 17 * screenHeight / 20 + 5, WHITE);
                DrawText("Back", screenWidth / 2 - MeasureText("Back", GetFontDefault().baseSize) * 2, 17 * screenHeight / 20, 40, YELLOW);
                DrawText(".", screenWidth / 2 - MeasureText(".", GetFontDefault().baseSize) * 1.5, screenHeight / 2, 30, BLUE);
            }

        EndDrawing();
    }

    UnloadSound(fxSelect);
    UnloadTexture(tankTex);

    CloseWindow();       // Close window and OpenGL context
}