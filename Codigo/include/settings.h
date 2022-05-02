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

    bool player_collision_check;

    Vector2 player_collision_pos;

    int player_score;
    int player_lives;
    float player_speed;

    
    int player_bullet_time_shot;
    float player_bullet_speed;
    Rectangle player_bullet_pos;
    float player_bullet_rotation;
    double player_bullet_time_active;
    //---------------------------------

    // Enemy
    //---------------------------------
    Texture2D enemy_texture;
    Vector2 enemy_texture_origin;
    int enemy_amount;
    int enemy_lives[10];
    float enemy_speed;
    float enemy_bullet_speed[10];
    Rectangle enemy_pos[10];
    float enemy_rotation[10];
    Rectangle enemy_bullet_pos[10];
    float enemy_bullet_rotation[10];
    Vector2 enemy_collision_pos[10];
    bool enemy_collision_check;
    int enemy_time_spawn;
    int enemy_counter;
    int enemy_on_screen;
    int enemy_random_rotate[10];
    int enemy_bullet_time_shot[10];
    double enemy_bullet_time_active[10];
    int enemy_kills;

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

    // Map
    //---------------------------------
    Texture2D map_texture;
    Rectangle map_pos[15][41];
    //---------------------------------

    // Save
    //---------------------------------
    bool save_game;
    //---------------------------------

    //Load
    //---------------------------------
    char load_file[100];
    bool load_game;
    //---------------------------------
} cfg;
typedef struct HIGHSCORE
{
    char name[10];
    int score;
} HIGHSCORE;
#endif