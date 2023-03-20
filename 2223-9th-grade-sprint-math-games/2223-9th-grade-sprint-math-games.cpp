#include <iostream>
#include <raylib.h>
using namespace std;

int main()
{
    // Set up the screen parameters
    const int screenWidth = 1000;
    const int screenHeight = 550;
    InitWindow(screenWidth, screenHeight, "twenty-one");

    // Set up the grid parameters
    const int gridSize = 50;
    const Color gridColor = LIGHTGRAY;

    // Main game loop
    while (!WindowShouldClose())
    {

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

        EndDrawing();
    }

    CloseWindow();

    return 0;
}