#include "raylib.h"
#include "settings.h"
#include "string.h"
#include "stdio.h"

#define MAX_INPUT_CHARS 9

void highscoresCrashFix(void);
void inputNames(cfg *settings)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'
    int letter_count = 0;
    settings->frames_counter = 0;
    int position_ranking;
    highscoresCrashFix();
    //--------------------------------------------------------------------------------------

    HIGHSCORE scorestemp[5];                              // Array for the highscores
    FILE *highscores = fopen("bin/highscores.bin", "rb"); // Open the file

    for (int i = 0; i < 5; i++)
    {
        fread(&scorestemp[i], sizeof(HIGHSCORE), 1, highscores);
    }
    fclose(highscores);

    for (int i = 4; i >= 0; i--) // Writes the new highscore in the array
    {
        if (settings->player_score > scorestemp[i].score)
        {
            strcpy(scorestemp[i + 1].name, scorestemp[i].name);
            scorestemp[i + 1].score = scorestemp[i].score;
            position_ranking = i;
        }
    }

    Sound fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    // Main window loop --------------------------------------------------------------------
    while (!settings->exit_window && !WindowShouldClose()) // Detect window close button or ESC key
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
            if ((key >= 32) && (key <= 125) && (letter_count < MAX_INPUT_CHARS))
            {
                name[letter_count] = (char)key;
                name[letter_count + 1] = '\0'; // Add null terminator at the end of the string.
                letter_count++;
                PlaySound(fx_select);
            }

            key = GetCharPressed(); // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letter_count--;
            if (letter_count < 0)
            {
                letter_count = 0;
            }
            name[letter_count] = '\0';
            PlaySound(fx_select);
        }

        settings->frames_counter++;

        if (IsKeyReleased(KEY_ENTER) && letter_count > 0)
        {
            PlaySound(fx_select);

            if (settings->player_score > scorestemp[4].score)
            {
                FILE *highscores = fopen("bin/highscores.bin", "wb");
                strcpy(scorestemp[position_ranking].name, name);
                scorestemp[position_ranking].score = settings->player_score;
                for (int i = 0; i < 5; i++)
                {
                    fwrite(&scorestemp[i], sizeof(HIGHSCORE), 1, highscores);
                }
                fclose(highscores);
            }

            WaitTime(200);
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

        DrawText(TextFormat("INPUT CHARS: %i/%i", letter_count, MAX_INPUT_CHARS), GetScreenWidth() / 2 - MeasureText(TextFormat("INPUT CHARS: %i/%i", letter_count, MAX_INPUT_CHARS), 20) / 2, 250, 20, DARKGRAY);

        if (letter_count < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((settings->frames_counter / 20) % 2) == 0)
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
            settings->select = 5;
            settings->exit_window = true;
        }
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fx_select);
    //--------------------------------------------------------------------------------------
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

void highscoresCrashFix(void)
{
    //! Highscores crash fix
    // If it doesn't find the highscores file, it will create it, avoids crashing
    if (!FileExists("bin/highscores.bin"))
    {
        FILE *noscores = fopen("bin/highscores.bin", "wb"); // Create highscores file
        HIGHSCORE scores[5] =                               // Creates a preselected array with madeup scores
            {
                {"AAA", 1},
                {"BBB", 2},
                {"CCC", 3},
                {"DDD", 4},
                {"EEE", 5},
            };
        fwrite(scores, sizeof(scores), 1, noscores); // Writes the madeup scores to the file
        fclose(noscores);                            // Close the file
    }
}