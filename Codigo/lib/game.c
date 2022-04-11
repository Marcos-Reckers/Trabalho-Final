#include "raylib.h"
#include "pauseMenu.h"
#include "settings.h"
#include "header.h"
#include "drawPlayer.h"
#include "movePlayer.h"
#include "collision.h"
#include "energyCell.h"

void game(cfg *settings)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    // Window
    settings->game_sreen_width = GetScreenWidth();
    settings->game_screen_height = GetScreenHeight() - 50;
    settings->exit_window = false;

    // General
    settings->frames_counter = 0;
    settings->pause = false;
    settings->energy_cell_active = true;
    settings->pause_select = 0;

    // Audio
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    Image energy_cell = LoadImage("Assets/energia_nobg.png");
    ImageResize(&energy_cell, 24, 30);
    settings->energy_cell = LoadTextureFromImage(energy_cell);
    UnloadImage(energy_cell);

    // Player
    settings->player_lives = 3;
    settings->player_score = 1600;
    settings->player_speed = 5;
    settings->player_pos.x = GetRandomValue(0, settings->game_sreen_width - settings->player_pos.width);
    settings->player_pos.y = GetRandomValue(0, settings->game_screen_height - settings->player_pos.height);
    settings->player_pos.width = 40;
    settings->player_pos.height = 40;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose())
    {
        // Initialization
        //-----------------------------
        settings->player_collision_pos.x = settings->player_pos.x;
        settings->player_collision_pos.y = settings->player_pos.y;

        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ESCAPE))
        {
            PlaySound(settings->fx_select);
            WaitTime(10);
            settings->pause = true;
        }

        else
        {
            settings->frames_counter++;
        }
        movePlayer(settings);
        collision(settings);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        pauseMenu(settings);
        header(settings);
        drawPlayer(settings);
        energyCell(settings);

        DrawText("Hello World!", 100, 100, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            settings->select = 4;
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(settings->fx_select);
    //--------------------------------------------------------------------------------------
}