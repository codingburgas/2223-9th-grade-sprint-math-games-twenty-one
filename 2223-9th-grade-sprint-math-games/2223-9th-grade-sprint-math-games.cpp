#include <iostream>
#include <raylib.h>

using namespace std;

// Set up the screen parameters
const int screenWidth = 400;
const int screenHeight = 300;





void gridLayout()
{
    DrawText("+", screenWidth/8 - 15, screenHeight/6 - 30, 60, BLUE);
    DrawText("-", screenWidth/8 - 15, (screenHeight / 3) + 20, 60, BLUE);
    DrawText("/", screenWidth/8 - 20, screenHeight - 70, 60, BLUE);
    DrawText("x", screenWidth/4 + 35, screenHeight / 6 - 30, 60, BLUE);
    DrawText("/", screenWidth / 4 + 30, screenHeight / 6 + 75, 60, BLUE);
    DrawText("-", screenWidth / 4 + 35, (screenHeight / 3)*2 + (screenHeight/3)/6 + 10, 60, BLUE);
}

//Move function
void move(Vector2 &position)
{
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        if(position.x > 0)
            position.x -= 12;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        if(position.x < screenWidth - 90)
            position.x += 12;
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        if (position.y > 0)
            position.y -= 12;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        if(position.y < screenHeight - 75)
            position.y += 12;
    }
}
//Main function
int main()
{
    SetTargetFPS(60);

    Vector2 position;
    position.x = 0;
    position.y = 0;
    InitWindow(screenWidth, screenHeight, "twenty-one");

    Texture2D mainCharacter = LoadTexture("images/binary_king.png");
    Image icon = LoadImage("images/icon.png");
    SetWindowIcon(icon);
    // Set up the grid parameters
    const int gridSize = 100;
    const Color gridColor = LIGHTGRAY;

    int counter = 0;
    // Main game loop
    while (!WindowShouldClose())
    {
        move(position);
        BeginDrawing();
        gridLayout();

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
