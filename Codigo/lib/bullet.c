#include "raylib.h"
#include "object.h"
#include "player_1.h"
#include <math.h>

//  bullet VARIABLES ============================================================================
//  bullet = MakeObject(
//         "Assets/bullet_u.png",
//         (Rectangle){GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()), (0.075 * GetScreenWidth()), (0.075 * GetScreenWidth())}, // body
//         (Vector2){(0.075 * GetScreenWidth()) / 2, (0.075 * GetScreenWidth()) / 2},                                                                      // origin
//         3.0                                                                                                                                             // speed
//     );


OBJECT UpdateBullet(OBJECT bullet , OBJECT player_1)
{
    // Draw bullet.body ------------------------------------------------------------
    Rectangle bullet_drawrectangle;
    bullet_drawrectangle = bullet.body;
    bullet_drawrectangle.x += bullet.body.width / 2;
    bullet_drawrectangle.y += bullet.body.height / 2;

    // Move ----------------------------------------------------------------------
    float body_position_x = bullet.body.x;
    float body_position_y = bullet.body.y;

    if (IsKeyPressed(KEY_SPACE) && player_1.rotation == 90 )
    {
        bullet.body.x += bullet.speed * cos( bullet.rotation);
    }

    else if (IsKeyPressed(KEY_SPACE) && player_1.rotation == -90 )
    {
        bullet.body.x += bullet.speed * cos( bullet.rotation);
    }
    else if (IsKeyPressed(KEY_SPACE) && player_1.rotation == 0 )
    {
        bullet.body.y += bullet.speed * sin( bullet.rotation);
    }
    else if (IsKeyPressed(KEY_SPACE) && player_1.rotation == 180 )
    {
        bullet.body.y += bullet.speed * sin( bullet.rotation);
    }

    // Window --------------------------------------------------------------------------
    if (bullet.body.x >= (GetScreenWidth() - bullet.body.width) || bullet.body.x <= 0)
    {
        bullet.body.x = body_position_x;
    }

    if (bullet.body.y >= (GetScreenHeight() - bullet.body.height) || bullet.body.y <= 0)
    {
        bullet.body.y = body_position_y;
    }
    //==================================================================================

    return bullet;
}