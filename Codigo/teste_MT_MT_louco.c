#include "raylib.h"
#include <stdlib.h>

int game()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    int framesCounter = 0;
    int select = 0;
    bool pause = 0;
    bool exitWindow = false;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_P)) pause = !pause;

        if (!pause)
        {

        }
         else framesCounter++;
    }

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            if ( pause && (( framesCounter / 30 ) % 2 ))
            {
                DrawText("PAUSED", 350, 200, 30, GRAY);
            } 
                
            DrawFPS(10, 10);

        EndDrawing();
    //----------------------------------------------------------------------------------
        
        if ( WindowShouldClose() )
        {
            select = 4;
            exitWindow = true;
        }

    return 0;
}

Player UpdatePlayer(player_Rec , player_speed)
{

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        
            // Draw player_Rec ------------------------------------------------------------
            Rectangle player_drawrectangle;
            player_drawrectangle = player_Rec;
            player_drawrectangle.x += player_Rec.width/2;
            player_drawrectangle.y += player_Rec.height/2;

            // Move -----------------------------------------------------------------------
            int rotation = 0;
            float player_speed = 3.0;
            float player_Rec_position_x = player_Rec.x;
            float player_Rec_position_y = player_Rec.y;

            if (IsKeyDown(KEY_RIGHT))
            {
                player_Rec.x += player_speed;
                rotation = 90;
            }
            else if (IsKeyDown(KEY_LEFT))
            {
                player_Rec.x -= player_speed;
                rotation = -90;
            }
            else if (IsKeyDown(KEY_UP))
            {
                player_Rec.y -= player_speed;
                rotation = 0;
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                player_Rec.y += player_speed;
                rotation = 180;
            }
            
            // Window --------------------------------------------------------------------------
            if (player_Rec.x >= (GetScreenWidth()-player_Rec.width) || player_Rec.x <= 0)
            {
                player_Rec.x = player_Rec_position_x;
            }

            if (player_Rec.y >= (GetScreenHeight()-player_Rec.height) || player_Rec.y <= 0)
            {
                player_Rec.y = player_Rec_position_y;
            }
            //==================================================================================
           
        }
}

int player()
{
    
    
    // PLAYER VARIABELS =====================================================================
    // Textures (for getting width and height)
    Texture2D player_texture = LoadTexture("Assets/player_u.png");  

    // Source rectangle (part of the texture to use for drawing)
    Rectangle player_sourceRec = { 0 , 0 , player_texture.width , player_texture.height };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle player_Rec = { GetRandomValue( 0 , GetScreenWidth() ) , GetRandomValue( 0 , GetScreenHeight() ), ( 0.075 * GetScreenWidth() ) , ( 0.075 * GetScreenWidth() )};

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 player_origin = {player_Rec.width/2 , player_Rec.height/2};
    

    //======================================================================================

    UpdatePlayer();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        DrawTexturePro( player_texture , player_sourceRec , player_drawrectangle , player_origin , (float)rotation , WHITE);

        EndDrawing();
      
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture( player_texture );
        
    //--------------------------------------------------------------------------------------

    return 0;
}