#include "raylib.h"
#include <stdlib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "BattleINF");


    // PLAYER VARIABELS

    // Textures (for getting width and height)
    Texture2D scarfy = LoadTexture("Assets/jogador_sem_fundo.png"); 

    int frameWidth = scarfy.width;
    int frameHeight = scarfy.height;

    // Source rectangle (part of the texture to use for drawing)
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, 20*3, 20*4 };

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 origin = { screenWidth/2.0f, screenHeight/2.0f };

    int rotation = 0;
    
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // MOVE
        if (IsKeyDown(KEY_RIGHT))
            destRec.x += 2.0f;
        else if (IsKeyDown(KEY_LEFT))
            destRec.x -= 2.0f;
        else if (IsKeyDown(KEY_UP))
            destRec.y -= 2.0f;
        else if (IsKeyDown(KEY_DOWN))
            destRec.y += 2.0f;
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexturePro(scarfy, sourceRec, destRec, origin, (float)rotation, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(scarfy);
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}