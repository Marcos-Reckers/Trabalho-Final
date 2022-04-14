#include "raylib.h"

#define NUM_FRAMES_PER_LINE 5
#define NUM_LINES 5

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "raylib [textures] example - sprite explosion");

    InitAudioDevice();

    // Load explosion sound
    Sound fxBoom = LoadSound("resources/boom.wav");

    // Load explosion texture
    Texture2D explosion = LoadTexture("resources/explosion.png");

    // Init variables for animation
    float frameWidth = (float)(explosion.width / NUM_FRAMES_PER_LINE); // Sprite one frame rectangle width
    float frameHeight = (float)(explosion.height / NUM_LINES);         // Sprite one frame rectangle height
    int currentFrame = 0;
    int currentLine = 0;

    Rectangle frameRec = {0, 0, frameWidth, frameHeight};
    Vector2 position = {0.0f, 0.0f};

    bool active = false;
    int frames_counter = 0;

    SetTargetFPS(120);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Check for mouse button pressed and activate explosion (if not active)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !active)
        {
            position = GetMousePosition();
            active = true;

            position.x -= frameWidth / 2.0f;
            position.y -= frameHeight / 2.0f;

            PlaySound(fxBoom);
        }

        // Compute explosion animation frames
        if (active)
        {
            frames_counter++;

            if (frames_counter > 2)
            {
                currentFrame++;

                if (currentFrame >= NUM_FRAMES_PER_LINE)
                {
                    currentFrame = 0;
                    currentLine++;

                    if (currentLine >= NUM_LINES)
                    {
                        currentLine = 0;
                        active = false;
                    }
                }

                frames_counter = 0;
            }
        }

        frameRec.x = frameWidth * currentFrame;
        frameRec.y = frameHeight * currentLine;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw explosion required frame rectangle
        if (active)
            DrawTextureRec(explosion, frameRec, position, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(explosion); // Unload texture
    UnloadSound(fxBoom);      // Unload sound

    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}