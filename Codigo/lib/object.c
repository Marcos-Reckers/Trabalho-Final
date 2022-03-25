

#include "raylib.h"
#include "object.h"

OBJECT MakeObject(int texture_path , Rectangle body , Vector2 origin ,  int speed )
{
    
    OBJECT object =
        {   
            LoadTexture(texture_path),
            (Rectangle){ 0 , 0 , object.texture.width , object.texture.height},
            body,
            origin,
            (Vector2){ 0 , 0 },
            speed,
            0
        };
        return object;
}