#include "raylib.h"
#include <stdlib.h>

// Types and Structures Definition
typedef enum GameScreen {TITLE = 0, GAMEPLAY, HIGHSCORES, ENDING, QUIT} GameScreen;

// Main entry point
int main(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int select = 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    // Main game loop
    while (!WindowShouldClose()){    // Detect window close button or ESC key
        // Update

        // Navigation on TITLE menu
        if (IsKeyPressed(KEY_DOWN)){
            select += 1;
            select %= 4; // Transform select into a value between 0 and 3
        }
        if (IsKeyPressed(KEY_UP)){
            select -= 1;
            if (select < 0){ // If select is negative, go to the maximum possible value: 3
                select = 4 - abs(select % 4);
            }
            else{
                select %= 4;
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
                    // TODO: Change to HIGHSCORES screen
                }
            } break;
        case 2:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    // TODO: Change to ENDING screen
                }
            } break;
        case 3:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    CloseWindow();
                    return 0;
                }
            } break;
        default: break;
        }
        
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
            DrawText("TITLE SCREEN", 20, 20, 40, RAYWHITE);
            if (select == 0){
                DrawText("Start", screenWidth / 2, screenHeight / 4, 20, YELLOW);
                DrawText("High-Scores", screenWidth / 2, screenHeight / 4 + 50, 20, RAYWHITE);
                DrawText("Credits", screenWidth / 2, screenHeight / 4 + 100, 20, RAYWHITE);
                DrawText("Quit", screenWidth / 2, screenHeight / 4 + 150, 20, RAYWHITE);
            }
            if (select == 1){
                DrawText("Start", screenWidth / 2, screenHeight / 4, 20, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2, screenHeight / 4 + 50, 20, YELLOW);
                DrawText("Credits", screenWidth / 2, screenHeight / 4 + 100, 20, RAYWHITE);
                DrawText("Quit", screenWidth / 2, screenHeight / 4 + 150, 20, RAYWHITE);
            }
            if (select == 2){
                DrawText("Start", screenWidth / 2, screenHeight / 4, 20, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2, screenHeight / 4 + 50, 20, RAYWHITE);
                DrawText("Credits", screenWidth / 2, screenHeight / 4 + 100, 20, YELLOW);
                DrawText("Quit", screenWidth / 2, screenHeight / 4 + 150, 20, RAYWHITE);
            }
            if (select == 3){
                DrawText("Start", screenWidth / 2, screenHeight / 4, 20, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2, screenHeight / 4 + 50, 20, RAYWHITE);
                DrawText("Credits", screenWidth / 2, screenHeight / 4 + 100, 20, RAYWHITE);
                DrawText("Quit", screenWidth / 2, screenHeight / 4 + 150, 20, YELLOW);
            }

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}