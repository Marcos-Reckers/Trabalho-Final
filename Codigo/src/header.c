#include "raylib.h"
#include "settings.h"

void header(cfg *settings)
{
    // Draw
    //--------------------------------------------------

    DrawRectangle(0, 0, GetScreenWidth(), 50, DARKGRAY);

    for (int i = 1; i <= settings->player_lives; i++)
    {
        DrawTexture(settings->right_tank, 10 + (50 * i), 10, WHITE);
    }

    DrawText(TextFormat("SCORE %d", settings->player_score), 700, 10, 40, YELLOW);

    DrawText(TextFormat("LEVEL %d", settings->level), GetScreenWidth() / 2 - MeasureText(TextFormat("LEVEL %d", settings->level), 20), 10, 40, YELLOW);

    //--------------------------------------------------
}
óvcasuovisdjv
sdv
adeuiovfh
sdvj
sdvj
sdfvj
sdv
osdjv
isdj
vjsdv
sdjv
sdjv
sdjv
djv

