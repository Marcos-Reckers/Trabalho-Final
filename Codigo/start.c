#include "raylib.h"
#include <stdlib.h>

#define SCREENWIDTH 800
#define SCREENHEIGHT 450


int startscreen(void)
{
    int select = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("BATTLEINF", SCREENWIDTH / 4 + 120, SCREENHEIGHT / 4 - 50, 40, LIME);
        
        if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S)){
            select += 1;
            select = abs(select % 2);
        }
        if (IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W)){
            select -= 1;
            select = abs(select % 2);
        }
        
        switch (select){
        case 0:
            DrawText("Quit", SCREENWIDTH / 4 + 120, SCREENHEIGHT / 4 + 100, 20, RAYWHITE);
            DrawText("Start", SCREENWIDTH / 4 + 120, SCREENHEIGHT / 4, 20, YELLOW);
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)){
                return select;
            }
            break;

        case 1:
            DrawText("Start", SCREENWIDTH / 4 + 120, SCREENHEIGHT / 4, 20, RAYWHITE);
            DrawText("Quit", SCREENWIDTH / 4 + 120, SCREENHEIGHT / 4 + 100, 20, YELLOW);
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)){
                return select;
            }
            break;
        }
        
        EndDrawing();
    }
    return select;
}