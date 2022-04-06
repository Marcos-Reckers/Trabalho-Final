#include "raylib.h"
#include "object.h"

//  PLAYER_1 VARIABLES ============================================================================
// player_1 = MakeObject(
//         "Assets/player_u.png",
//         (Rectangle){GetRandomValue(0, GetscreenWidth()), GetRandomValue(0, GetScreenHeight()), (0.075 * GetscreenWidth()), (0.075 * GetscreenWidth())}, // body
//         (Vector2){(0.075 * GetscreenWidth()) / 2, (0.075 * GetscreenWidth()) / 2},                                                                      // origin
//         3.0                                                                                                                                             // speed
//     );

Rectangle UpdatePlayer_1(OBJECT *player_1)
{
    // Draw player_1.body ------------------------------------------------------------
    Rectangle player_drawrectangle;
    player_drawrectangle = player_1->body;
    player_drawrectangle.x += player_1->body.width / 2;
    player_drawrectangle.y += player_1->body.height / 2;

    // Move ----------------------------------------------------------------------
    float body_position_x = player_1->body.x;
    float body_position_y = player_1->body.y;

    if (IsKeyDown(KEY_RIGHT))
    {
        player_1->body.x += player_1->speed;
        player_1->rotation = 90;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        player_1->body.x -= player_1->speed;
        player_1->rotation = -90;
    }
    else if (IsKeyDown(KEY_UP))
    {
        player_1->body.y -= player_1->speed;
        player_1->rotation = 0;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        player_1->body.y += player_1->speed;
        player_1->rotation = 180;
    }

    // Window --------------------------------------------------------------------------
    if (player_1->body.x >= (GetscreenWidth() - player_1->body.width) || player_1->body.x <= 0)
    {
        player_1->body.x = body_position_x;
    }

    if (player_1->body.y >= (GetScreenHeight() - player_1->body.height) || player_1->body.y <= 0)
    {
        player_1->body.y = body_position_y;
    }
    //==================================================================================
    return player_drawrectangle;
}