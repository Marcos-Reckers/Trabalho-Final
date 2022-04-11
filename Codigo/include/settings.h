#ifndef settings_H_
#define settings_H_

typedef struct cfg
{
    // Game settings
    bool pause;
    bool exit_window;
    int frames_counter;
    int select;
    int pause_select;
    Sound fx_select;
    Texture2D right_tank;
    Texture2D left_tank;

    // Player
    int player_score;
    int player_lives;
    int player_speed;
    int player_bullet_speed;
} cfg;

#endif