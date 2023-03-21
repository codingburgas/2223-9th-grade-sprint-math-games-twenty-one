#include <iostream>
#include <raylib.h>
using namespace std;

int main()
{
    SetTargetFPS(60);
 

    // Set up the screen parameters
    const int screenWidth = 1000;
    const int screenHeight = 550;

    Vector2 pos;
    pos.x = screenWidth / 2;
    pos.y = screenHeight / 2;
    InitWindow(screenWidth, screenHeight, "twenty-one");

    Texture2D mainCharacter = LoadTexture("binary_king.png");

    // Set up the grid parameters
    const int gridSize = 50;
    const Color gridColor = LIGHTGRAY;


    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_LEFT))
        {
            pos.x -= 10;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            pos.x += 10;
        }
        if (IsKeyDown(KEY_UP))
        {
            pos.y -= 10;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            pos.y += 10;
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

        DrawTexture(mainCharacter, pos.x, pos.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
}