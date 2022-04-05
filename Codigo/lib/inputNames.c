#include "raylib.h"

#define MAX_INPUT_CHARS 9

int inputNames(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;
    int framesCounter = 0;
    int select = 0;
    bool exitWindow = false;

    Sound fxSelect = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    SetTargetFPS(60); // Set our game to run at 10 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow && !WindowShouldClose()) // Detect window close button or ESC key
    {
        Rectangle textBox = {GetScreenWidth() / 2.0f - 150, 180, 300, 50};

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

        if (IsKeyReleased(KEY_ENTER) && letterCount > 0)
        {
            PlaySound(fxSelect);
            select = 0;
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("ENTER YOUR NAME:", GetScreenWidth() / 2 - MeasureText("ENTER YOUR NAME:", 20) / 2, 140, 20, GRAY);

        DrawRectangleRec(textBox, LIGHTGRAY);
        DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        DrawText(name, (int)textBox.x - MeasureText(name, 40) / 2 + textBox.width / 2, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), GetScreenWidth() / 2 - MeasureText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 20) / 2, 250, 20, DARKGRAY);

        if (letterCount < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter / 20) % 2) == 0)
            {
                 DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40) / 2 + textBox.width / 2, (int)textBox.y + 12, 40, MAROON);
            }
        }
        else
        {
            DrawText("Press BACKSPACE to delete chars...", GetScreenWidth() / 2 - MeasureText("Press BACKSPACE to delete chars...", 20) / 2, 300, 20, GRAY);
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