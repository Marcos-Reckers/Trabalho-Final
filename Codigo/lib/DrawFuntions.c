#include "raylib.h"
#include "object.h"

void DrawPause(bool pause, int framesCounter)
{
    if (pause && ((framesCounter / 30) % 2))
    {
        DrawText("PAUSED", 350, 200, 30, GRAY);
    }
}

void DrawOBJECT(Texture2D texture, OBJECT object)
{
    DrawTexturePro(texture , object.source , object.body , object.origin , object.rotation , WHITE);
}