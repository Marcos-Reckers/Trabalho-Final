#include <raylib.h>
#include <stdlib.h>

// Main entry point
int start(void)
{
    // Initialization
    // -----------------------------------------------------
    int select = 0;
    char startOptions[5][50] = {"Play\0", "Load\0", "Highscores\0", "Credits\0", "Exit\0"};
    bool exitWindow = false;

    Image logo = LoadImage("Assets/battleinflogo.png");
    Image tank = LoadImage("Assets/player_r.png");
    Image tankL = LoadImage("Assets/player_l.png");
    ImageResize(&logo, (0.800 * GetScreenWidth()), (0.190 * GetScreenHeight()));
    ImageResize(&tank, (0.035 * GetScreenWidth()), (0.050 * GetScreenHeight()));
    ImageResize(&tankL, (0.035 * GetScreenWidth()), (0.050 * GetScreenHeight()));
    Texture2D logoTex = LoadTextureFromImage(logo);
    Texture2D tankTex = LoadTextureFromImage(tank);
    Texture2D tankTexL = LoadTextureFromImage(tankL);
    UnloadImage(logo);
    UnloadImage(tank);
    UnloadImage(tankL);

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Main window loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();
        float scale = (screenHeight * screenWidth) / (600.0 * 800.0);

        // Navigation on TITLE menu

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

        if (IsKeyReleased(KEY_ENTER))
        {
            exitWindow = true;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(logoTex, screenWidth / 2 - logoTex.width / 2, 0.150 * screenHeight, WHITE);

        for (int i = 0; i < 5; i++)
        {
            if (i == select)
            {
                DrawTexture(tankTex, screenWidth / 2 - MeasureText(startOptions[i], 20 * scale) - 0.060 * screenWidth, 0.40 * screenHeight + (75 * i) + tankTex.height/4 , WHITE);
                DrawText(startOptions[i], screenWidth / 2 - MeasureText(startOptions[i], 20 * scale), 0.40 * screenHeight + (75 * i) , 40 * scale, YELLOW);
                DrawTexture(tankTexL, screenWidth / 2 + MeasureText(startOptions[i], 20 * scale) + 0.020 * screenWidth, 0.40 * screenHeight + (75 * i) + tankTexL.height/4 , WHITE);
            }
            else
            {
                DrawText(startOptions[i], screenWidth / 2 - MeasureText(startOptions[i], 20 * scale), 0.40 * screenHeight + (75 * i), 40 * scale, RAYWHITE);
            }
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            select = 4;
            exitWindow = true;
        }
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(logoTex);
    UnloadTexture(tankTex);
    UnloadTexture(tankTexL);
    UnloadSound(fxSelect);
    //--------------------------------------------------------------------------------------

    return select;
}