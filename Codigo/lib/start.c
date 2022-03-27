#include <raylib.h>
#include <stdlib.h>


// Main entry point
int start(void)
{
   // Initialization
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int select = 0;
    int logoMove = 0;
    bool exitWindow = false;

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    Image logo = LoadImage("Assets/battleinflogo.png");
    Image tank = LoadImage("Assets/player_r.png");
    Image tankL = LoadImage("Assets/player_l.png");
    ImageResize(&logo, 639, 114);
    ImageResize(&tank, 30, 30);
    ImageResize(&tankL, 30, 30);
    Texture2D logoTex = LoadTextureFromImage(logo);
    Texture2D tankTex = LoadTextureFromImage(tank);
    Texture2D tankTexL = LoadTextureFromImage(tankL);
    UnloadImage(logo);
    UnloadImage(tank);
    UnloadImage(tankL);

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {    
        // Navigation on TITLE menu
        SetExitKey(0); // Remove Esc as an exit key

        if (logoMove <= 0.850 * screenHeight)
        {
            logoMove += 0.010 * screenHeight;
            if (logoMove % 6 == 0){
                PlaySound(fxSelect);
            }     
        }

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select += 1;
            select %= 5; // Transform select into a value between 0 and 3
        }
        else if (IsKeyPressed(KEY_UP))
        {
            PlaySound(fxSelect);
            select -= 1;

            if (select < 0) // If select is negative, go to the maximum possible value: 3
            { 
                select = 5 - abs(select % 5);
            }
            else
            {
                select %= 5;
            }
        }

        // Depending on select value and if enter is pressed, change the screen
        switch (select)
        {
            case 0: // GAMEPLAY
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        select = 0;
                        exitWindow = true;
                    }
                } break;

            case 1: // LOAD
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        // TODO: Change to LOAD screen
                    }
                } break;

            case 2: // HIGHSCORES
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        // TODO: Change to HIGHSCORES screen
                    }
                } break;

            case 3: // CREDITS
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        select = 3;
                        exitWindow = true;
                    }
                } break;

            case 4: //QUIT
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        select = 4;
                        exitWindow = true;
                    }
                } break;
        }

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(logoTex, screenWidth/2 - logoTex.width/2, screenHeight - logoMove, WHITE);

            if (logoMove > 0.850 * screenHeight)
            { 
                DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, 0.400 * screenHeight, 40, RAYWHITE);
                DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, 0.475 * screenHeight, 40, RAYWHITE);
                DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, 0.550 * screenHeight, 40, RAYWHITE);
                DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, 0.700 * screenHeight, 40, RAYWHITE);
                DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, 0.775 * screenHeight, 40, RAYWHITE);

                if (select == 0)
                {
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.400 * screenHeight, WHITE);
                    DrawText("Start", screenWidth / 2 - MeasureText("Start", GetFontDefault().baseSize) * 2, 0.400 * screenHeight, 40, YELLOW);
                    DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Start", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.400 * screenHeight, WHITE);
                }

                if (select == 1)
                {
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.475 * screenHeight, WHITE);
                    DrawText("Load", screenWidth / 2 - MeasureText("Load", GetFontDefault().baseSize) * 2, 0.475 * screenHeight, 40, YELLOW);
                    DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Load", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.475 * screenHeight, WHITE);
                }

                if (select == 2)
                {
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.550 * screenHeight, WHITE);
                    DrawText("High-Scores", screenWidth / 2 - MeasureText("High-Scores", GetFontDefault().baseSize) * 2, 0.550 * screenHeight, 40, YELLOW);
                    DrawTexture(tankTexL, screenWidth / 2 + MeasureText("High-Scores", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.550 * screenHeight, WHITE);
                }

                if (select == 3)
                {
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.700 * screenHeight, WHITE);
                    DrawText("Credits", screenWidth / 2 - MeasureText("Credits", GetFontDefault().baseSize) * 2, 0.700 * screenHeight, 40, YELLOW);
                    DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Credits", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.700 * screenHeight, WHITE);
                }

                if (select == 4)
                {
                    DrawTexture(tankTex, screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2 - 0.060 * screenWidth, 0.775 * screenHeight, WHITE);
                    DrawText("Quit", screenWidth / 2 - MeasureText("Quit", GetFontDefault().baseSize) * 2, 0.775 * screenHeight, 40, YELLOW);
                    DrawTexture(tankTexL, screenWidth / 2 + MeasureText("Quit", GetFontDefault().baseSize) * 2 + 0.020 * screenWidth, 0.775 * screenHeight, WHITE);
                }

            }

        EndDrawing();

        if (WindowShouldClose())
        {
            select = 4;
            exitWindow = true;
        }
    }

    UnloadTexture(logoTex);
    UnloadTexture(tankTex);
    UnloadTexture(tankTexL);
    UnloadSound(fxSelect);

    return select;
}