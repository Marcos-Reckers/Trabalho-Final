#include "raylib.h"


// NOTE: Storage positions must start with 0, directly related to file memory layout
typedef enum {
    STORAGE_POSITION_SCORE      = 0,
    STORAGE_POSITION_HISCORE    = 1
} StorageData;

int highscores(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int score = 0;
    int hiscore = 0;
    int framesCounter = 0;
    int select = 0;
    bool exitWindow = false;
    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_R))
        {
            score = GetRandomValue(1000, 2000);
            hiscore = GetRandomValue(2000, 4000);
        }

        if (IsKeyPressed(KEY_S))
        {
            SaveStorageValue(STORAGE_POSITION_SCORE, score);
            SaveStorageValue(STORAGE_POSITION_HISCORE, hiscore);
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            // NOTE: If requested position could not be found, value 0 is returned
            score = LoadStorageValue(STORAGE_POSITION_SCORE);
            hiscore = LoadStorageValue(STORAGE_POSITION_HISCORE);
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select = 4;
        }
        if (select == 4 && IsKeyReleased(KEY_ENTER)) //TODO RESOLVER BUG DE 2 ENTERS
        {
            select = 0;
            break;
        }
        
    
        framesCounter++;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("YOUR LAST SCORE: %i", score), 280, 130, 40, MAROON);
            DrawText(TextFormat("HI-SCORE: %i", hiscore), 210, 200, 50, RAYWHITE);

            DrawText("Press R to generate random numbers", 220, 40, 20, LIGHTGRAY);
            DrawText("Press S to SAVE values", 250, 310, 20, LIGHTGRAY);
            DrawText("Press SPACE to LOAD values", 252, 350, 20, LIGHTGRAY);


            //TODO Implementar função de gerar botão QUIT!!!
            DrawText("BACK", GetScreenWidth() / 2 - MeasureText("BACK", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, RAYWHITE);

            if (select == 4)
                {
                    DrawText("BACK", GetScreenWidth() / 2 - MeasureText("BACK", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, YELLOW);
                }

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            select = 0;
            exitWindow = true;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxSelect);
    //--------------------------------------------------------------------------------------
    return select;
}