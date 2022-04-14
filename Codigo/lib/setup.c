#include <raylib.h>
#include "settings.h"

#define NUM_OPTIONS 3

void setup(cfg *settings)
{
    // setup window
    //===============================
    int screen_width = 1000;
    int screen_height = 650;
    InitWindow(screen_width, screen_height, "BattleINF");
    SetTargetFPS(60);
    SetExitKey(0); // Remove Esc as an exit key
    InitAudioDevice();

    // setup logo
    //================================ 
    Image logo = LoadImage("Assets/battleinflogo.png");
    ImageResize(&logo, (0.800 * GetScreenWidth()), (0.190 * GetScreenHeight()));
    settings->logo_texture = LoadTextureFromImage(logo);
    UnloadImage(logo);

    // Load assets textures for options
    //===============================
    Image right_tank_im = LoadImage("Assets/player_r.png");
    ImageResize(&right_tank_im, 30, 30);
    settings->right_tank = LoadTextureFromImage(right_tank_im);
    UnloadImage(right_tank_im);

    Image left_tank_im = LoadImage("Assets/player_l.png");
    ImageResize(&left_tank_im, 30, 30);
    settings->left_tank = LoadTextureFromImage(left_tank_im);
    UnloadImage(left_tank_im);

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
    settings->player_texture = LoadTexture("Assets/player.png");
    settings->player_texture_origin = (Vector2){settings->player_pos.width /2, settings->player_pos.height /2};
    settings->player_lives = 3;
    settings->player_score = 1600;
    settings->player_speed = 5;
    settings->player_rotation = 0;
    settings->player_pos.width = 40;
    settings->player_pos.height = 40;
    settings->player_pos.x = GetRandomValue(0, settings->game_screen_width - settings->player_pos.width);
    settings->player_pos.y = GetRandomValue(50, settings->game_screen_height - settings->player_pos.height);
    
    // Enemy
    //===============================
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
    Image energy_cell = LoadImage("Assets/energia_nobg.png");
    ImageResize(&energy_cell, 24, 30);
    settings->energy_cell_texture = LoadTextureFromImage(energy_cell);
    UnloadImage(energy_cell);

    settings->energy_cell_rec = (Rectangle){settings->game_screen_width * 2 - settings->energy_cell_texture.width / 2, settings->game_screen_height * 2 - settings->energy_cell_texture.height / 2, settings->energy_cell_texture.width, settings->energy_cell_texture.height};

    settings->energy_cell_active = false;
    settings->energy_cell_spawn = false;
    settings->energy_cell_time_spawn = 0;
}