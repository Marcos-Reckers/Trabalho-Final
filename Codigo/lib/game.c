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

void game(cfg *settings)
{
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
}