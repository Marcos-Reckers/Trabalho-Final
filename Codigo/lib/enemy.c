#include "raylib.h"
#include "object.h"

//  enemy VARIABLES ============================================================================
// enemy = MakeObject(
//         "Assets/enemy_u.png",
//         (Rectangle){GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()), (0.075 * GetScreenWidth()), (0.075 * GetScreenWidth())}, // body
//         (Vector2){(0.075 * GetScreenWidth()) / 2, (0.075 * GetScreenWidth()) / 2},                                                                      // origin
//         3.0                                                                                                                                             // speed
//     );


OBJECT UpdateEnemy(OBJECT enemy)
{
    // Draw enemy.body ------------------------------------------------------------
    Rectangle enemy_drawrectangle;
    enemy_drawrectangle = enemy.body;
    enemy_drawrectangle.x += enemy.body.width / 2;
    enemy_drawrectangle.y += enemy.body.height / 2;

    // Move ----------------------------------------------------------------------
    float body_position_x = enemy.body.x;
    float body_position_y = enemy.body.y;

    if (IsKeyDown(KEY_D))
    {
        enemy.body.x += enemy.speed;
        enemy.rotation = 90;
    }
    else if (IsKeyDown(KEY_A))
    {
        enemy.body.x -= enemy.speed;
        enemy.rotation = -90;
    }
    else if (IsKeyDown(KEY_W))
    {
        enemy.body.y -= enemy.speed;
        enemy.rotation = 0;
    }
    else if (IsKeyDown(KEY_S))
    {
        enemy.body.y += enemy.speed;
        enemy.rotation = 180;
    }

    // Window --------------------------------------------------------------------------
    if (enemy.body.x >= (GetScreenWidth() - enemy.body.width) || enemy.body.x <= 0)
    {
        enemy.body.x = body_position_x;
    }

    if (enemy.body.y >= (GetScreenHeight() - enemy.body.height) || enemy.body.y <= 0)
    {
        enemy.body.y = body_position_y;
    }
    //==================================================================================

    return enemy;
}