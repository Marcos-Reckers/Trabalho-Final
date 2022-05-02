#include "raylib.h"
#include <stdio.h>
#include "pauseMenu.h"
#include "settings.h"
#include "header.h"
#include "drawPlayer.h"
#include "enemy.h"
#include "movePlayer.h"
#include "moveEnemy.h"
#include "collision.h"
#include "energyCell.h"
#include "bullets.h"
#include "drawMap.h"

void game(cfg *settings)
{

    // Assets
    //------------------------------
    settings->map_texture = LoadTexture("Assets/Parede_tijolo.png");
    settings->enemy_texture = LoadTexture("Assets/enemy.png");
    settings->player_texture = LoadTexture("Assets/player.png");
    settings->bullet_texture = LoadTexture("Assets/bullet.png");
    Image energy_cell = LoadImage("Assets/energia_nobg.png");
    ImageResize(&energy_cell, 24, 30);
    settings->energy_cell_texture = LoadTextureFromImage(energy_cell);
    UnloadImage(energy_cell);
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    //------------------------------

    if (!settings->save_game)
    {
        // Initialization
        //--------------------------------------------------------------------------------------

        // Window
        //===============================
        settings->game_screen_width = GetScreenWidth();
        settings->game_screen_height = GetScreenHeight() - 50;
        settings->exit_window = false;

        FILE *map_file = fopen(TextFormat("txt/level%d.txt", settings->level), "r");
        for (int line = 0; line < 15; line++)
        {
            for (int column = 0; column < 41; column++)
            {
                char c;
                fscanf(map_file, "%c", &c);
                printf("%c", c);
                if (c == '#')
                {
                    settings->map_pos[line][column].x = column * 25;
                    settings->map_pos[line][column].y = (line * 40) + 50;
                    settings->map_pos[line][column].width = 25;
                    settings->map_pos[line][column].height = 40;
                }
                else
                {
                    settings->map_pos[line][column].x = 0;
                    settings->map_pos[line][column].y = 0;
                    settings->map_pos[line][column].width = 0;
                    settings->map_pos[line][column].height = 0;
                }
            }
        }
        fclose(map_file);

        //===============================

        // General
        //===============================
        settings->frames_counter = 0;
        settings->pause = false;
        settings->pause_select = 0;
        //===============================

        // Player
        //===============================
        settings->player_lives = 3;
        settings->player_speed = 4;
        settings->player_rotation = 90;
        settings->player_pos.width = 40;
        settings->player_pos.height = 40;

        do
        {
            settings->player_collision_check = false;
            settings->player_pos.x = GetRandomValue(0, settings->game_screen_width - settings->player_pos.width);
            settings->player_pos.y = GetRandomValue(50, settings->game_screen_height - settings->player_pos.height);

            for (int line = 0; line < 15; line++)
            {
                for (int column = 0; column < 40; column++)
                {
                    if (CheckCollisionRecs(settings->player_pos, settings->map_pos[line][column]))
                    {
                        settings->player_collision_check = true;
                    }
                }
            }
        } while (settings->player_collision_check);

        // Enemy
        settings->enemy_texture_origin = (Vector2){0, 0};
        settings->enemy_time_spawn = 0;
        settings->enemy_amount = 10;
        settings->enemy_counter = 0;
        settings->enemy_on_screen = 0;
        settings->enemy_speed = 2;
        settings->enemy_kills = 0;

        for (int i = 0; i < settings->enemy_amount; i++)
        {
            settings->enemy_lives[i] = 0;
            settings->enemy_pos[i] = (Rectangle){GetScreenWidth(), GetScreenHeight(), 40, 40};
            settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
        }

        // Energy cell
        //===============================
        settings->energy_cell_active = true;

        settings->energy_cell_rec = (Rectangle){settings->game_screen_width * 2 - settings->energy_cell_texture.width / 2, settings->game_screen_height * 2 - settings->energy_cell_texture.height / 2, settings->energy_cell_texture.width, settings->energy_cell_texture.height};

        settings->energy_cell_active = false;
        settings->energy_cell_spawn = false;
        settings->energy_cell_time_spawn = 0;
        //===============================

        // Bullets
        //===============================

        // Player
        //---------------------------------
        settings->player_bullet_time_shot = 0;

        settings->player_bullet_speed = 5;
        settings->player_bullet_pos.width = 10;
        settings->player_bullet_pos.height = 10;
        settings->player_bullet_pos.x = -10;
        settings->player_bullet_pos.y = -10;

        //---------------------------------

        // enemy
        //---------------------------------
        for (int i = 0; i < settings->enemy_amount; i++)
        {
            settings->enemy_bullet_time_shot[i] = 0;
            settings->enemy_bullet_speed[i] = 0;
            settings->enemy_bullet_pos[i].width = 10;
            settings->enemy_bullet_pos[i].height = 10;
            settings->enemy_bullet_pos[i].x = GetScreenWidth() + 20;
            settings->enemy_bullet_pos[i].y = GetScreenHeight() + 20;
        }

        //---------------------------------

        //===============================

        //--------------------------------------------------------------------------------------
    }

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose() && settings->player_lives > 0)
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
            moveEnemy(settings);

            collision(settings);
            spawnEnemy(settings);
        }
        else
        {
            settings->energy_cell_time_spawn = 0;
        }
        //----------------------------------------------------------------------------------

        //? Draw
        //?----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        header(settings);

        drawMap(settings);

        drawPlayer(settings);

        drawEnemy(settings);

        energyCell(settings);

        bullets(settings);

        pauseMenu(settings);

        EndDrawing();
        //?----------------------------------------------------------------------------------

        if(settings->enemy_kills == settings->enemy_amount)
        {
            DrawText("LEVEL CLEAR!", GetScreenWidth() / 2 - MeasureText("LEVEL CLEAR!", 50) / 2, GetScreenHeight() / 2 - 50, 50, GREEN);
            WaitTime(1000);
            break;
        }


        if (WindowShouldClose())
        {
            settings->select = 5;
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(settings->fx_select);
    UnloadTexture(settings->map_texture);
    //--------------------------------------------------------------------------------------
}