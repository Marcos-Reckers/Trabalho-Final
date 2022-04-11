#include "raylib.h"
#include <stdio.h>
#include "pauseMenu.h"
#include "settings.h"
#include "header.h"
#include "drawPlayer.h"
#include "drawEnemy.h"
#include "movePlayer.h"
#include "collision.h"
#include "energyCell.h"

void game(cfg *settings)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    // Window
    //===============================
    settings->game_screen_width = GetScreenWidth();
    settings->game_screen_height = GetScreenHeight() - 50;
    settings->exit_window = false;
    settings->level = 1;
    //===============================


    // General
    //===============================
    settings->frames_counter = 0;
    settings->pause = false;
    settings->energy_cell_active = true;
    settings->pause_select = 0;
    //===============================

    // Audio
    //===============================
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    //===============================

    // Player
    //===============================
    settings->player_lives = 3;
    settings->player_score = 1600;
    settings->player_speed = 5;
    settings->player_pos.width = 40;
    settings->player_pos.height = 40;
    settings->player_pos.x = GetRandomValue(0, settings->game_screen_width - settings->player_pos.width);
    settings->player_pos.y = GetRandomValue(50, settings->game_screen_height - settings->player_pos.height);

    // Enemy
    settings->enemy_amount = 5;
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        settings->enemy_lives[i] = 3;
        settings->enemy_speed[i] = 5;
        settings->enemy_pos[i].width = 40;
        settings->enemy_pos[i].height = 40;
        bool collision;
        do
        {
            collision = false;
            settings->enemy_pos[i].x = GetRandomValue(0, settings->game_screen_width - settings->enemy_pos[i].width);
            settings->enemy_pos[i].y = GetRandomValue(50, settings->game_screen_height - settings->enemy_pos[i].height);
            
            // collision testing
            for (int j = 0; j < i; j++)
            {
                if (CheckCollisionRecs(settings->enemy_pos[i], settings->enemy_pos[j]))
                {
                    collision = true;
                }
            }
        } while (collision);
    }

    // Energy cell
    //===============================
    Image energy_cell = LoadImage("Assets/energia_nobg.png");
    ImageResize(&energy_cell, 24, 30);
    settings->energy_cell_texture = LoadTextureFromImage(energy_cell);
    UnloadImage(energy_cell);

    settings->energy_cell_rec = (Rectangle){settings->game_screen_width * 2 - settings->energy_cell_texture.width/2,settings->game_screen_height * 2 - settings->energy_cell_texture.height/2, settings->energy_cell_texture.width, settings->energy_cell_texture.height};
    
    settings->energy_cell_active = false;
    settings->energy_cell_spawn = false;
    settings->energy_cell_time_spawn = 0;
    //===============================

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
        drawEnemy(settings);
        energyCell(settings);

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