#include "raylib.h"
#include <stdlib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    float velocidade = 3.0;
    InitWindow(screenWidth, screenHeight, "BattleINF");


    // PLAYER VARIABELS

    // Textures (for getting width and height)
    Texture2D player = LoadTexture("Assets/player_u.png");  

    int frameWidth = (player.width);
    int frameHeight = (player.height);

    // Source rectangle (part of the texture to use for drawing)
    Rectangle sourceRec = { 0, 0, (float)frameWidth, (float)frameHeight };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, 60,60};

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 origin = { 0,0 };

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
        {
            destRec.x += velocidade;
            player = LoadTexture("Assets/player_r.png");
            // rotation = 90;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            destRec.x -= velocidade;
            player = LoadTexture("Assets/player_l.png");
            // rotation = 270;
        }
        else if (IsKeyDown(KEY_UP))
        {
            destRec.y -= velocidade;
            player = LoadTexture("Assets/player_u.png");
            // rotation = 0;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            destRec.y += velocidade;
            player = LoadTexture("Assets/player_d.png");
            // rotation = 180;
        }
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        
        DrawTexturePro(player, sourceRec, destRec, origin, (float)rotation, WHITE);

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(player); 
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}