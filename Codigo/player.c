#include "raylib.h"
#include <stdlib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    int rotation = 0, counter = 0;
    InitWindow(screenWidth, screenHeight, "BattleINF");
    Rectangle screen = {0, 0, GetScreenWidth(), GetScreenHeight()};
    InitAudioDevice();


    // PLAYER VARIABELS =====================================================================

    // Load move sound
    Sound fxMove = LoadSound("Assets\\NES - Battle City JPN - Sound Effects\\Battle City SFX (1).wav");

    // Textures (for getting width and height)
    Texture2D player = LoadTexture("Assets/player_u.png");  

    int player_frameWidth = (player.width);
    int player_frameHeight = (player.height);

    // Source rectangle (part of the texture to use for drawing)
    Rectangle player_sourceRec = { 0, 0, (float)player_frameWidth, (float)player_frameHeight };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle player_destRec = { screenWidth/2.0f, screenHeight/2.0f, 60,60};

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 player_origin = { 0,0 };
    
    float player_speed = 3.0;
    
    //======================================================================================



    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // PLAYER =====================================================================
        float player_position_x = player_destRec.x;
        float player_position_y = player_destRec.y;

        // Move -----------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT))
        {
            player_destRec.x += player_speed;
            player = LoadTexture("Assets/player_r.png");
            counter++;
            if (counter >= 4){
                PlaySound(fxMove);
                counter = 0;
            }
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            player_destRec.x -= player_speed;
            player = LoadTexture("Assets/player_l.png");
            counter++;
            if (counter >= 4){
                PlaySound(fxMove);
                counter = 0;
            }
        }
        else if (IsKeyDown(KEY_UP))
        {
            player_destRec.y -= player_speed;
            player = LoadTexture("Assets/player_u.png");
            counter++;
            if (counter >= 4){
                PlaySound(fxMove);
                counter = 0;
            }
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            player_destRec.y += player_speed;
            player = LoadTexture("Assets/player_d.png");
            counter++;
            if (counter >= 4){
                PlaySound(fxMove);
                counter = 0;
            }
        }
        
        // COLLISION PLAYER ================================================================
        
        // Window --------------------------------------------------------------------------
        if (player_destRec.x >= (GetScreenWidth()-player_destRec.width) || player_destRec.x <= 0)
        {
            player_destRec.x = player_position_x;
        }

        if (player_destRec.y >= (GetScreenHeight()-player_destRec.height) || player_destRec.y <= 0)
        {
            player_destRec.y = player_position_y;
        }
        //==================================================================================


        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        // Draw Player
        DrawTexturePro(player, player_sourceRec, player_destRec, player_origin, (float)rotation, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(player);
    UnloadSound(fxMove);
    
    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}