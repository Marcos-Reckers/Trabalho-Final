// TODO: implementar tela de creditos

#include <raylib.h>
#include <stdlib.h>
#include "credits.h"

// Main entry point
int start(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int select = 0, logoMove = 0;
    bool exitWindow = false;

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    Image logo = LoadImage("Assets/battleinflogo.png");
    Image tank = LoadImage("Assets/player_r.png");
    ImageResize(&logo, 639, 114);
    ImageResize(&tank, 30, 30);
    Texture2D logoTex = LoadTextureFromImage(logo);
    Texture2D tankTex = LoadTextureFromImage(tank);
    UnloadImage(logo);
    UnloadImage(tank);

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()){    // Detect window close button or ESC key
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        if (logoMove <= 19 * screenHeight / 20){
            logoMove += screenHeight / 80;
            if (logoMove * 80 % 6 == 0){
                PlaySound(fxSelect);
            }     
        }

        if (IsKeyPressed(KEY_DOWN)){
            PlaySound(fxSelect);
            select += 1;
            select %= 5; // Transform select into a value between 0 and 3
        }
        else if (IsKeyPressed(KEY_UP)){
            PlaySound(fxSelect);
            select -= 1;
            if (select < 0){ // If select is negative, go to the maximum possible value: 3
                select = 5 - abs(select % 5);
            }
            else{
                select %= 5;
            }
        }

        // Depending on select value and if enter is pressed, change the screen
        switch (select)
        {
        case 0: // GAMEPLAY
            {
                if (IsKeyPressed(KEY_ENTER)){
                    exitWindow = true;
                }
            } break;
        case 1: // LOAD
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to LOAD screen
                }
            } break;
        case 2: // HIGHSCORES
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to HIGHSCORES screen
                }
            } break;
        case 3: // CREDITS
            {
                if (IsKeyPressed(KEY_ENTER)){
                    exitWindow = true;
                }
            } break;
        case 4:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    exitWindow = true;
                }
            } break;
        default: break;
        }

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(logoTex, screenWidth/2 - logoTex.width/2, screenHeight - logoMove, WHITE);

            if (logoMove > 19 * screenHeight / 20){ 
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, RAYWHITE);

                if (select == 0){
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2.25 - 50, screenHeight / 2.75 + 5, WHITE);
                    DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, YELLOW);
                }
                if (select == 1){
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2.25 - 50, screenHeight / 2.75 + 45, WHITE);
                    DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, YELLOW);
                }
                if (select == 2){
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2.25 - 50, screenHeight / 2.75 + 85, WHITE);
                    DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, YELLOW);
                }
                if (select == 3){
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2.25 - 50, screenHeight / 2.75 + 155, WHITE);
                    DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, YELLOW);
                }
                if (select == 4){
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2.25 - 50, screenHeight / 2.75 + 195, WHITE);
                    DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, YELLOW);
                }
            }

        EndDrawing();

        if (WindowShouldClose()){
            select = 4;
            exitWindow = true;
        }
    }

    UnloadTexture(logoTex);
    UnloadTexture(tankTex);
    UnloadSound(fxSelect);

    return select;
}