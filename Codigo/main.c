#include "raylib.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

int main(void)
{
    int score = 0, lscore = 1600, select = 0;
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
    SetTargetFPS(60);

    
    while (select == 0)
    {
        select = startScreen();
    }
    
    CloseWindow();
    return 0;
}