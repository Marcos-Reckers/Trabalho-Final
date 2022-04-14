#include "raylib.h"

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "raylib [texture] example - texture rectangle");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D scarfy = LoadTexture("resources/scarfy.png"); // Texture loading

    Vector2 position = {350.0f, 280.0f};
    Rectangle frameRec = {0.0f, 0.0f, (float)scarfy.width / 6, (float)scarfy.height};
    int currentFrame = 0;

    int frames_counter = 0;
    int framesSpeed = 8; // Number of spritesheet frames shown by second

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        frames_counter++;

        if (frames_counter >= (60 / framesSpeed))
        {
            frames_counter = 0;
            currentFrame++;

            if (currentFrame > 5)
                currentFrame = 0;

            frameRec.x = (float)currentFrame * (float)scarfy.width / 6;
        }

        if (IsKeyPressed(KEY_RIGHT))
            framesSpeed++;
        else if (IsKeyPressed(KEY_LEFT))
            framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED)
            framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED)
            framesSpeed = MIN_FRAME_SPEED;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(scarfy, 15, 40, WHITE);
        DrawRectangleLines(15, 40, scarfy.width, scarfy.height, LIME);
        DrawRectangleLines(15 + (int)frameRec.x, 40 + (int)frameRec.y, (int)frameRec.width, (int)frameRec.height, RED);

        DrawText("FRAME SPEED: ", 165, 210, 10, DARKGRAY);
        DrawText(TextFormat("%02i FPS", framesSpeed), 575, 210, 10, DARKGRAY);
        DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, DARKGRAY);

        for (int i = 0; i < MAX_FRAME_SPEED; i++)
        {
            if (i < framesSpeed)
                DrawRectangle(250 + 21 * i, 205, 20, 20, RED);
            DrawRectangleLines(250 + 21 * i, 205, 20, 20, MAROON);
        }

        DrawTextureRec(scarfy, frameRec, position, WHITE); // Draw part of the texture

        DrawText("(c) Scarfy sprite by Eiden Marsal", screen_width - 200, screen_height - 20, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(scarfy); // Texture unloading

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
