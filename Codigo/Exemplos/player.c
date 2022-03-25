#include "raylib.h"
#include <stdlib.h>

int player()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;
    int rotation = 0;
    int counter = 0;
    int select = 0;
    int framesCounter = 0;
    Rectangle screen = {0, 0, GetScreenWidth(), GetScreenHeight()};
    bool pause = 0;
    bool exitWindow = false;

    


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
    Vector2 player_origin = {player_destRec.width/2, player_destRec.height/2};
    
    float player_speed = 3.0;
    float player_position_x = 0;
    float player_position_y = 0;
    Rectangle player_drawrectangle;


    
    //======================================================================================



    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_BACKSPACE)) pause = !pause;

        if (!pause)
        {


            // PLAYER =====================================================================

            player_position_x = player_destRec.x;
            player_position_y = player_destRec.y;
            player_drawrectangle = player_destRec;
            player_drawrectangle.x += player_destRec.width/2;
            player_drawrectangle.y += player_destRec.height/2;
            // Move -----------------------------------------------------------------------
            if (IsKeyDown(KEY_RIGHT))
            {
                player_destRec.x += player_speed;
                rotation = 90;
                counter++;
                if (counter >= 4){
                    PlaySound(fxMove);
                    counter = 0;
                }
            }
            else if (IsKeyDown(KEY_LEFT))
            {
                player_destRec.x -= player_speed;
                rotation = -90;
                counter++;
                if (counter >= 4){
                    PlaySound(fxMove);
                    counter = 0;
                }
            }
            else if (IsKeyDown(KEY_UP))
            {
                player_destRec.y -= player_speed;
                rotation = 0;
                counter++;
                if (counter >= 4){
                    PlaySound(fxMove);
                    counter = 0;
                }
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                player_destRec.y += player_speed;
                rotation = 180;
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
           
        }
        else framesCounter++;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        // Draw Player
        DrawTexturePro(player, player_sourceRec,player_drawrectangle, player_origin, (float)rotation, WHITE);
        if (pause && ((framesCounter/30)%2)) DrawText("PAUSED", 350, 200, 30, GRAY);

        DrawFPS(10, 10);
        EndDrawing();
        //----------------------------------------------------------------------------------
        
        if (WindowShouldClose()){
            select = 4;
            exitWindow = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(player);
    UnloadSound(fxMove);
    
    //--------------------------------------------------------------------------------------

    return select;
}