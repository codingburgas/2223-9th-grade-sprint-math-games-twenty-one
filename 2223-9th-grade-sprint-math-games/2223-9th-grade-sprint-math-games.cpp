#include <iostream>
#include <raylib.h>
using namespace std;

int main()
{
    SetTargetFPS(60);

    // Set up the screen parameters
    const int screenWidth = 1000;
    const int screenHeight = 550;
    InitWindow(screenWidth, screenHeight, "twenty-one");

    // Set up the grid parameters
    const int gridSize = 50;
    const Color gridColor = LIGHTGRAY;

    // Set up the player's starting position
    Rectangle player = { screenWidth / 2 - 20, screenHeight / 2 - 20, 50, 50 }; 

    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_LEFT))
        {
            player.x -= 10;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            player.x += 10;
        }
        if (IsKeyDown(KEY_UP))
        {
            player.y -= 10;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            player.y += 10;
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
        DrawRectangleRec(player, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}