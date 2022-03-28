#include "raylib.h"
#include "object.h"
#include <math.h>

int DrawPause(bool pause, int framesCounter, int select)
{
    if (pause && ((framesCounter / 30) % 2))
    {
        DrawText("PAUSED", 350, 100, 30, GRAY);
    }

    if (pause)
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            select += 1;
            select %= 3; // Transform select into a value between 0 and 2
        }
        else if (IsKeyPressed(KEY_UP))
        {
            select -= 1;

            if (select < 0) // If select is negative, go to the maximum possible value: 2
            {
                select = 3 - abs(select % 3);
            }
            else
            {
                select %= 3;
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
                }
            }
            break;

            case 1: // LOAD
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    // TODO: Change to LOAD screen
                }
            }
            break;

            case 2: // QUIT
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    select = 4;
                }
            }
            break;
        }
        DrawText("Return", GetScreenWidth() / 2 - MeasureText("Return", GetFontDefault().baseSize) * 2, 0.400 * GetScreenHeight(), 40, RAYWHITE);

        DrawText("Back to Menu", GetScreenWidth() / 2 - MeasureText("Back to Menu", GetFontDefault().baseSize) * 2, 0.700 * GetScreenHeight(), 40, RAYWHITE);

        DrawText("Quit Without Saving", GetScreenWidth() / 2 - MeasureText("Quit Without Saving", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, RAYWHITE);

        if (select == 0)
        {

            DrawText("Return", GetScreenWidth() / 2 - MeasureText("Return", GetFontDefault().baseSize) * 2, 0.400 * GetScreenHeight(), 40, YELLOW);
        }

        if (select == 1)
        {

            DrawText("Back to Menu", GetScreenWidth() / 2 - MeasureText("Back to Menu", GetFontDefault().baseSize) * 2, 0.700 * GetScreenHeight(), 40, YELLOW);
        }

        if (select == 2)
        {

            DrawText("Quit Without Saving", GetScreenWidth() / 2 - MeasureText("Quit Without Saving", GetFontDefault().baseSize) * 2, 0.775 * GetScreenHeight(), 40, YELLOW);
        }
    }
    if (IsKeyPressed(KEY_K))
    {
        printf("\n%d", select);
    }
    
    return select;
}

void DrawOBJECT(Texture2D texture, OBJECT object)
{
    DrawTexturePro(texture, object.source, object.body, object.origin, object.rotation, WHITE);
}