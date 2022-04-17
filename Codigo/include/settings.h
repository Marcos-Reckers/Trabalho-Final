#ifndef settings_H_
#define settings_H_

#include "raylib.h"

typedef struct cfg
{
    // Game settings
    //---------------------------------
    int game_screen_width;
    int game_screen_height;
    bool pause;
    bool exit_window;
    int frames_counter;
    int select;
    int pause_select;
    Sound fx_select;
    Texture2D right_tank;
    Texture2D left_tank;
    int level;
    //---------------------------------

    // Player
    //---------------------------------
    Texture2D player_texture;
    Vector2 player_texture_origin;
    Rectangle player_pos;
    float player_rotation;

    Vector2 player_collision_pos;

    int player_score;
    int player_lives;
    int player_speed;

    int player_bullet_speed;
    Rectangle player_bullet_pos[5];
    float player_bullet_rotation[5];
    //---------------------------------

    // Enemy
    //---------------------------------
    Texture2D enemy_texture;
    Vector2 enemy_texture_origin;
    int enemy_amount;
    int enemy_lives[10];
    int enemy_speed[10];
    int enemy_bullet_speed[100];
    Rectangle enemy_pos[10];
    float enemy_rotation[10];
    Vector2 enemy_bullet_pos[10];
    float enemy_bullet_rotation[10];
    Vector2 enemy_collision_pos[10];
    bool enemy_collision_check;
    int enemy_time_spawn;
    int enemy_counter;
    int enemy_on_screen;
    //---------------------------------

    // Energy cell
    //---------------------------------
    Rectangle energy_cell_rec;
    Texture2D energy_cell_texture;

    bool energy_cell_active;
    int energy_cell_time_active;

    bool energy_cell_spawn;
    int energy_cell_time_spawn;

    // Bullets
    //---------------------------------
    Texture2D bullet_texture;
    Vector2 bullet_texture_origin;
    //---------------------------------

} cfg;

#endif