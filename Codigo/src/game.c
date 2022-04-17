#include "raylib.h"
#include <stdio.h>
#include "pauseMenu.h"
#include "settings.h"
#include "header.h"
#include "drawPlayer.h"
#include "enemy.h"
#include "movePlayer.h"
#include "collision.h"
#include "energyCell.h"
#include "bullets.h"

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
    settings->pause_select = 0;
    //===============================

    // Audio
    //===============================
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");
    //===============================

    // Player
    //===============================
    settings->player_texture = LoadTexture("Assets/player.png");
    settings->player_texture_origin = (Vector2){settings->player_pos.width /2, settings->player_pos.height /2};
    settings->player_lives = 3;
    settings->player_score = 1600;
    settings->player_speed = 5;
    settings->player_rotation = 90;
    settings->player_pos.width = 40;
    settings->player_pos.height = 40;
    settings->player_pos.x = GetRandomValue(0, settings->game_screen_width - settings->player_pos.width);
    settings->player_pos.y = GetRandomValue(50, settings->game_screen_height - settings->player_pos.height);
    

    // Enemy
    settings->enemy_texture = LoadTexture("Assets/enemy.png");
    settings->enemy_texture_origin = (Vector2){0, 0};
    settings->enemy_time_spawn = 0;
    settings->enemy_amount = 10;
    settings->enemy_counter = 0;
    settings->enemy_on_screen = 0;

    for (int i = 0; i < settings->enemy_amount; i++)
    {
        settings->enemy_lives[i] = 0;
        settings->enemy_speed[i] = 3;
        settings->enemy_pos[i].width = 40;
        settings->enemy_pos[i].height = 40;
    }

    // Energy cell
    //===============================
    settings->energy_cell_active = true;
    Image energy_cell = LoadImage("Assets/energia_nobg.png");
    ImageResize(&energy_cell, 24, 30);
    settings->energy_cell_texture = LoadTextureFromImage(energy_cell);
    UnloadImage(energy_cell);

    settings->energy_cell_rec = (Rectangle){settings->game_screen_width * 2 - settings->energy_cell_texture.width / 2, settings->game_screen_height * 2 - settings->energy_cell_texture.height / 2, settings->energy_cell_texture.width, settings->energy_cell_texture.height};

    settings->energy_cell_active = false;
    settings->energy_cell_spawn = false;
    settings->energy_cell_time_spawn = 0;
    //===============================

    // Bullets
    //===============================

    // Player
    //---------------------------------
    settings->player_bullet_speed = 10;
    //---------------------------------

    //===============================

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose())
    {
        // Initialization
        //-----------------------------
        settings->player_collision_pos.x = settings->player_pos.x;
        settings->player_collision_pos.y = settings->player_pos.y;

        for (int i = 0; i < settings->enemy_amount; i++)
        {
            settings->enemy_collision_pos[i].x = settings->enemy_pos[i].x;
            settings->enemy_collision_pos[i].y = settings->enemy_pos[i].y;
        }

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

        if (!settings->pause)
        {
            movePlayer(settings);
            collision(settings);
            spawnEnemy(settings);
        }
        else
        {
            settings->energy_cell_time_spawn = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            header(settings);

            drawPlayer(settings);

            drawEnemy(settings);

            energyCell(settings);

            pauseMenu(settings);

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
    UnloadTexture(settings->player_texture);
    //--------------------------------------------------------------------------------------
}