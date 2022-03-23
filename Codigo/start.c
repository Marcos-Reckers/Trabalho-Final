// TODO: implementar tank nas opcoes, tela de creditos

#include "raylib.h"
#include <stdlib.h>

// Main entry point
int main(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int select = 0;
    bool exitWindow = false;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    InitAudioDevice();

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    Image logo = LoadImage("Assets/battleinflogo.png");
    ImageResize(&logo, 639, 114);
    Texture2D logoTex = LoadTextureFromImage(logo);
    UnloadImage(logo);

    Sound fxSelect = LoadSound("Assets\\NES - Battle City JPN - Sound Effects\\Battle City SFX (5).wav");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()){    // Detect window close button or ESC key
        // Update
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

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
        case 0:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to GAMEPLAY screen
                }
            } break;
        case 1:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to LOAD screen
                }
            } break;
        case 2:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to HIGHSCORES screen
                }
            } break;
        case 3:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to CREDITS screen
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

            DrawTexture(logoTex, screenWidth/2 - logoTex.width/2, screenWidth/25, WHITE);
            
            if (select == 0){
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2.25, screenHeight / 2.75, 45, YELLOW);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, RAYWHITE);
            }
            if (select == 1){
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2.25, screenHeight / 2.75 + 40, 45, YELLOW);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, RAYWHITE);
            }
            if (select == 2){
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2.25, screenHeight / 2.75 + 80, 45, YELLOW);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, RAYWHITE);
            }
            if (select == 3){
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2.25, screenHeight / 2.75 + 150, 45, YELLOW);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 190, 40, RAYWHITE);
            }
            if (select == 4){
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, screenHeight / 2.75, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 40, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 80, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, screenHeight / 2.75 + 150, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2.25, screenHeight / 2.75 + 190, 45, YELLOW);
            }

        EndDrawing();
    }

    UnloadTexture(logoTex);
    
    CloseWindow();        // Close window and OpenGL context

    return 0;
}