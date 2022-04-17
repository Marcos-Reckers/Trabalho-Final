#include "raylib.h"
#include <math.h>
#include "settings.h"

#define NUM_OPTIONS 5

void pauseMenu(cfg *settings)
{
    // Initialization
    // -----------------------------------------------------
    char pause_options[NUM_OPTIONS][50] = {"Resume\0", "Save\0" , "Restart\0", "Main Menu\0", "Exit\0"};
    //------------------------------------------------------

    // Main window loop
    //------------------------------------------------------
    if (settings->pause)
    {
        if (IsKeyPressed(KEY_DOWN))
        {   
            PlaySound(settings->fx_select);
            settings->pause_select += 1;
            settings->pause_select %= NUM_OPTIONS;
        }
        else if (IsKeyPressed(KEY_UP))
        {   
            PlaySound(settings->fx_select);
            settings->pause_select -= 1;
            if (settings->pause_select < 0)
            {
                settings->pause_select = NUM_OPTIONS - abs(settings->pause_select % NUM_OPTIONS);
            }
            else
            {
                settings->pause_select %= NUM_OPTIONS;
            }
        }

        if (IsKeyReleased(KEY_ENTER))
        {   
            PlaySound(settings->fx_select);
            WaitTime(90);
            switch (settings->pause_select)
            {
                case 0:
                    settings->pause = false;
                    break;

                case 1:
                    break;

                case 2:
                    break;

                case 3:
                    settings->select = 3;
                    settings->exit_window = true;
                    break;

                case 4:
                    settings->select = 4;
                    settings->exit_window = true;
                    break;
            }
        }
        

        //--------------------------------------------------

        // Draw
        //--------------------------------------------------

        if (settings->pause && ((settings->frames_counter / 30) % 2))
        {
            DrawText("PAUSED", GetScreenWidth() / 2 - MeasureText("PAUSED", 20) , 0.100 * GetScreenHeight(), 40, GRAY);
        }
        
        for (int i = 0; i < NUM_OPTIONS; i++)
        {
            if (i == settings->pause_select)
            {
                DrawText(pause_options[i],GetScreenWidth() / 2 - MeasureText(pause_options[i], 20) , 0.400 * GetScreenHeight() + i * 50, 40, YELLOW);
            }
            else
            {
                DrawText(pause_options[i],GetScreenWidth() / 2 - MeasureText(pause_options[i], 20) , 0.400 * GetScreenHeight() + i * 50, 40, RAYWHITE);
            }
        }

        //--------------------------------------------------
    }
}
