#include "raylib.h"
#include "settings.h"

void collision(cfg *settings)
{
    // Player collision with walls
    //----------------------------------------------------------------------------
    if (settings->player_pos.x < settings->game_screen_width / 2 || settings->player_pos.y < settings->game_screen_height / 2)
    {
        if (!CheckCollisionRecs((Rectangle){settings->player_pos.x - settings->player_pos.width, settings->player_pos.y - settings->player_pos.height, settings->player_pos.width, settings->player_pos.height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
        }
    }
    if (settings->player_pos.x < settings->game_screen_width / 2 || settings->player_pos.y > settings->game_screen_height / 2)
    {
        if (!CheckCollisionRecs((Rectangle){settings->player_pos.x - settings->player_pos.width, settings->player_pos.y + settings->player_pos.height, settings->player_pos.width, settings->player_pos.height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
        }
    }
    if (settings->player_pos.x > settings->game_screen_width / 2 || settings->player_pos.y < settings->game_screen_height / 2)
    {
        if (!CheckCollisionRecs((Rectangle){settings->player_pos.x + settings->player_pos.width, settings->player_pos.y - settings->player_pos.height, settings->player_pos.width, settings->player_pos.height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
        }
    }
    if (settings->player_pos.x > settings->game_screen_width / 2 || settings->player_pos.y > settings->game_screen_height / 2)
    {
        if (!CheckCollisionRecs((Rectangle){settings->player_pos.x + settings->player_pos.width, settings->player_pos.y + settings->player_pos.height, settings->player_pos.width, settings->player_pos.height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
        }
    }

    else
    {
        if (!CheckCollisionRecs((Rectangle){settings->player_pos.x + settings->player_pos.width, settings->player_pos.y + settings->player_pos.height, settings->player_pos.width, settings->player_pos.height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
        }
    }
    //----------------------------------------------------------------------------------------

    // Player collision with enemies
    //----------------------------------------------------------------------------------------
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        if (CheckCollisionRecs(settings->player_pos, settings->enemy_pos[i]))
        {
            settings->player_pos.x = settings->player_collision_pos.x;
            settings->player_pos.y = settings->player_collision_pos.y;
            settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
            settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
        }
    }
    //----------------------------------------------------------------------------------------

    // Enemy collision with walls
    //----------------------------------------------------------------------------------------
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        if (settings->enemy_pos[i].x < settings->game_screen_width / 2 || settings->enemy_pos[i].y < settings->game_screen_height / 2)
        {
            if (!CheckCollisionRecs((Rectangle){settings->enemy_pos[i].x - settings->enemy_pos[i].width, settings->enemy_pos[i].y - settings->enemy_pos[i].height, settings->enemy_pos[i].width, settings->enemy_pos[i].height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
        if (settings->enemy_pos[i].x < settings->game_screen_width / 2 || settings->enemy_pos[i].y > settings->game_screen_height / 2)
        {
            if (!CheckCollisionRecs((Rectangle){settings->enemy_pos[i].x - settings->enemy_pos[i].width, settings->enemy_pos[i].y + settings->enemy_pos[i].height, settings->enemy_pos[i].width, settings->enemy_pos[i].height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
        if (settings->enemy_pos[i].x > settings->game_screen_width / 2 || settings->enemy_pos[i].y < settings->game_screen_height / 2)
        {
            if (!CheckCollisionRecs((Rectangle){settings->enemy_pos[i].x + settings->enemy_pos[i].width, settings->enemy_pos[i].y - settings->enemy_pos[i].height, settings->enemy_pos[i].width, settings->enemy_pos[i].height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
        if (settings->enemy_pos[i].x > settings->game_screen_width / 2 || settings->enemy_pos[i].y > settings->game_screen_height / 2)
        {
            if (!CheckCollisionRecs((Rectangle){settings->enemy_pos[i].x + settings->enemy_pos[i].width, settings->enemy_pos[i].y + settings->enemy_pos[i].height, settings->enemy_pos[i].width, settings->enemy_pos[i].height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
        else
        {
            if (!CheckCollisionRecs((Rectangle){settings->enemy_pos[i].x + settings->enemy_pos[i].width, settings->enemy_pos[i].y + settings->enemy_pos[i].height, settings->enemy_pos[i].width, settings->enemy_pos[i].height}, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
    }
    //----------------------------------------------------------------------------------------

    // Enemy collision with Enemies
    //----------------------------------------------------------------------------------------
    for (int i = 0; i < settings->enemy_amount; i++)
    {
        for (int j = 0; j < settings->enemy_amount; j++)
        {
            if (CheckCollisionRecs(settings->enemy_pos[i], settings->enemy_pos[j]) && i != j)
            {
                settings->enemy_pos[i].x = settings->enemy_collision_pos[i].x;
                settings->enemy_pos[i].y = settings->enemy_collision_pos[i].y;
                
                settings->enemy_random_rotate[i] = GetRandomValue(0, 3);
            }
        }
    }
    //----------------------------------------------------------------------------------------

    // Player bullet collision
    //----------------------------------------------------------------------------------------

    // Player bullet time ative
    //-------------------------------------------------------------
    if (GetTime() > settings->player_bullet_time_active + 1)
    {
        settings->player_bullet_speed = 0;
        settings->player_bullet_pos.x = -10;
        settings->player_bullet_pos.y = -10;
        settings->player_bullet_time_active = 0;
    }
    //-------------------------------------------------------------

    // Player bullet collision with walls
    //-------------------------------------------------------------
    if (!CheckCollisionRecs(settings->player_bullet_pos, (Rectangle){0, 50, settings->game_screen_width, settings->game_screen_height}))
    {
        settings->player_bullet_speed = 0;
        settings->player_bullet_pos.x = -10;
        settings->player_bullet_pos.y = -10;
    }
    //-------------------------------------------------------------

    // Player bullet collision with enemies
    //-------------------------------------------------------------
    for (int j = 0; j < settings->enemy_amount; j++)
    {
        if (CheckCollisionRecs(settings->player_bullet_pos, settings->enemy_pos[j]))
        {
            settings->player_bullet_speed = 0;
            settings->player_bullet_pos.x = -10;
            settings->player_bullet_pos.y = -10;

            settings->enemy_pos[j].x = GetScreenWidth();
            settings->enemy_pos[j].y = GetScreenHeight();
            settings->enemy_lives[j]--;
            settings->enemy_on_screen--;

            settings->player_score += 800;
        }
    }
    //-------------------------------------------------------------

    //----------------------------------------------------------------------------------------
}