#ifndef object_H_
#define object_H_

#include "raylib.h"
#include <stdio.h>

typedef struct OBJECT
{   
    Texture2D texture;
    Rectangle source;
    Rectangle body;
    Vector2 origin;
    Vector2 position;
    int speed;
    int rotation;
} OBJECT;

OBJECT MakeObject(char *texture_path, Rectangle body , Vector2 origin, int speed);

#endif