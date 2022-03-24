#include "raylib.h"
#include <stdlib.h>

int bullet()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    int rotation = 0;
    InitWindow(screenWidth, screenHeight, "BattleINF");
    Rectangle screen = {0, 0, GetScreenWidth(), GetScreenHeight()};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // BULLET VARIABELS =====================================================================

        float bullet_speed = 5;
        // Textures (for getting width and height)
        Texture2D bullet = LoadTexture("Assets/Bullet_u.png");  

        int bullet_frameWidth = (bullet.width);
        int bullet_frameHeight = (bullet.height);

        // Source rectangle (part of the texture to use for drawing)
        Rectangle bullet_sourceRec = { 0, 0, (float)bullet_frameWidth, (float)bullet_frameHeight };

        // Destination rectangle (screen rectangle where drawing part of texture)
        Rectangle bullet_destRec = { screenWidth/3.0f, screenHeight/3.0f, 10, 20};

        // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
        Vector2 bullet_origin = { 0,0 };
        //======================================================================================

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw Bullet
        DrawTexturePro(bullet, bullet_sourceRec, bullet_destRec, bullet_origin, (float)rotation, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(bullet); 
    
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}