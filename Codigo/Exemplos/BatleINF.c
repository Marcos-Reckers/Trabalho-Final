#include "raylib.h"
#include <stdlib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    int rotation = 0;
    InitWindow(screenWidth, screenHeight, "BattleINF");
    Rectangle screen = {0, 0, GetScreenWidth(), GetScreenHeight()};


    // PLAYER VARIABELS =====================================================================

    float player_speed = 3.0;
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
    //======================================================================================



    // ENEMY VARIABELS =====================================================================

    float enemy_speed = 2.25;
    // Textures (for getting width and height)
    Texture2D enemy = LoadTexture("Assets/enemy_u.png");  

    int enemy_frameWidth = (enemy.width);
    int enemy_frameHeight = (enemy.height);

    // Source rectangle (part of the texture to use for drawing)
    Rectangle enemy_sourceRec = { 0, 0, (float)enemy_frameWidth, (float)enemy_frameHeight };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle enemy_destRec = { screenWidth/2.0f, screenHeight/2.0f, 60,60};

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 enemy_origin = { 0,0 };
    //======================================================================================



    
    
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // MOVE PLAYER =====================================================================
        if (IsKeyDown(KEY_RIGHT))
        {
            player_destRec.x += player_speed;
            player = LoadTexture("Assets/player_r.png");
            // rotation = 90;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            player_destRec.x -= player_speed;
            player = LoadTexture("Assets/player_l.png");
            // rotation = 270;
        }
        else if (IsKeyDown(KEY_UP))
        {
            player_destRec.y -= player_speed;
            player = LoadTexture("Assets/player_u.png");
            // rotation = 0;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            player_destRec.y += player_speed;
            player = LoadTexture("Assets/player_d.png");
            // rotation = 180;
        }

        // COLLISION PLAYER
        float x = player_destRec.x;
        float y = player_destRec.y;

        if (!CheckCollisionRecs(player_destRec,screen))
        {
            player_destRec.x = x;
            player_destRec.y = y;
        }
        
        
        //==================================================================================



        // MOVE ENEMY =====================================================================
        if (IsKeyDown(KEY_D))
        {
            enemy_destRec.x += enemy_speed;
            enemy = LoadTexture("Assets/enemy_r.png");
            // rotation = 90;
        }
        else if (IsKeyDown(KEY_A ))
        {
            enemy_destRec.x -= enemy_speed;
            enemy = LoadTexture("Assets/enemy_l.png");
            // rotation = 270;
        }
        else if (IsKeyDown(KEY_W))
        {
            enemy_destRec.y -= enemy_speed;
            enemy = LoadTexture("Assets/enemy_u.png");
            // rotation = 0;
        }
        else if (IsKeyDown(KEY_S))
        {
            enemy_destRec.y += enemy_speed;
            enemy = LoadTexture("Assets/enemy_d.png");
            // rotation = 180;
        }
        //==================================================================================



        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        // Draw Player
        DrawTexturePro(player, player_sourceRec, player_destRec, player_origin, (float)rotation, WHITE);

        // Draw Enemy
        DrawTexturePro(enemy, enemy_sourceRec, enemy_destRec, enemy_origin, (float)rotation, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(player); 
    UnloadTexture(enemy); 
    
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}