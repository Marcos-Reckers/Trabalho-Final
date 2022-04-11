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
    //---------------------------------

    // Player
    //---------------------------------
    int player_score;
    int player_lives;
    int player_speed;
    int player_bullet_speed;
    Rectangle player_pos;
    int player_rotation;
    Vector2 player_bullet_pos;
    int player_bullet_rotation;
    bool player_bullet_active;
    bool player_bullet_direction;
    Vector2 player_collision_pos;
    //---------------------------------

    // Enemy
    //---------------------------------
    int enemy_lives[100];
    int enemy_speed[100];
    int enemy_bullet_speed[100];
    Rectangle enemy_pos[100];
    int enemy_rotation[100];
    Vector2 enemy_bullet_pos[100];
    int enemy_bullet_rotation[100];
    bool enemy_bullet_active[100];
    bool enemy_bullet_direction[100];
    Vector2 enemy_collision_pos[100];
    //---------------------------------

    // Energy cell
    bool energy_cell_active;
    Vector2 cell_pos;
    Texture2D energy_cell;

} cfg;

#endif