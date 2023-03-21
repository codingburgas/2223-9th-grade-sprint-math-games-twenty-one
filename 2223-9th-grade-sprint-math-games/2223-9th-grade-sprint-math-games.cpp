#include <iostream>
#include <raylib.h>
using namespace std;

int main()
{
    SetTargetFPS(60);
 

    // Set up the screen parameters
    const int screenWidth = 400;
    const int screenHeight = 300;

    Vector2 position;
    position.x = 12;
    position.y = 10;
    InitWindow(screenWidth, screenHeight, "twenty-one");

    Texture2D mainCharacter = LoadTexture("binary_king.png");

    // Set up the grid parameters
    const int gridSize = 100;
    const Color gridColor = LIGHTGRAY;


    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_LEFT))
        {
            position.x -= 18;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            position.x += 18;
        }
        if (IsKeyDown(KEY_UP))
        {
            position.y -= 18;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            position.y += 18;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
    
        // Draw horizontal lines
        for (int i = 0; i < screenHeight; i += gridSize)
        {
            DrawLine(0, i, screenWidth, i, gridColor);
        }
        // Draw vertical lines
        for (int i = 0; i < screenWidth; i += gridSize)
        {
            DrawLine(i, 0, i, screenHeight, gridColor);
        }

        DrawTexture(mainCharacter, position.x, position.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
}
