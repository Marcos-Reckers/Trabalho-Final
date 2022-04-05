#include "raylib.h"

#define MAX_INPUT_CHARS 9

int inputNames(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = {GetScreenWidth() / 2.0f - 100, 180, 300, 50};

    int framesCounter = 0;
    int select = 0;
    bool exitWindow = false;

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    SetTargetFPS(60); // Set our game to run at 10 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                name[letterCount] = (char)key;
                name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed(); // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0)
                letterCount = 0;
            name[letterCount] = '\0';
        }

        framesCounter++;

        if (IsKeyPressed(KEY_DOWN))
        {
            PlaySound(fxSelect);
            select = 4;
        }

        if (select == 4 && IsKeyReleased(KEY_ENTER)) // TODO RESOLVER BUG DE 2 ENTERS
        {
            select = 0;
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

        DrawRectangleRec(textBox, LIGHTGRAY);
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

        if (letterCount < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
        }
        else
            DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);

        DrawText("NEXT", GetScreenWidth() / 2 - MeasureText("NEXT", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, RAYWHITE);

        if (select == 4)
        {
            DrawText("NEXT", GetScreenWidth() / 2 - MeasureText("NEXT", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, YELLOW);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            select = 4;
            exitWindow = true;
        }
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxSelect);
    //--------------------------------------------------------------------------------------
    return select;
}

// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126))
        keyPressed = true;

    return keyPressed;
}