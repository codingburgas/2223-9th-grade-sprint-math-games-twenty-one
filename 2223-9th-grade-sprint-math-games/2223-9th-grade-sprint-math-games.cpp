#include <iostream>
#include <raylib.h>

using namespace std;

// Set up the screen parameters
const int screenWidth = 400;
const int screenHeight = 300;



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

    //Rectangles
    Rectangle rec[3][4];
    bool flag = false;
    // Main game loop
    while (!WindowShouldClose())
    {
        move(position);
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
    
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                rec[i][j] = {(float)j* screenWidth / 4,(float)i* screenHeight / 3,screenWidth / 4, screenHeight / 3 };
                DrawRectangleRec(rec[i][j], WHITE);
                DrawRectangleLinesEx(rec[i][j], 1, BLACK);
            }
        }

        const char* level[3][4] = {
        "-", "+", "/", "-",
        "x", "-", "+", "x",
        "-", "+", "/", "x",
        };
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                DrawText(level[i][j], rec[i][j].x + (screenWidth / 4) / 2 - 15, rec[i][j].y + (screenHeight / 3) / 2 - 60 / 2, 60, BLUE);
            }
        }
        if (IsKeyDown(KEY_ENTER))
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (CheckCollisionPointRec(position, rec[i][j]))
                    {
                        flag = true;
                    }
                }
            }
        }

        if (flag)
        {
            cout << "agiowabgjkabg;w";
        }
        //// Draw horizontal lines
        //for (int i = 0; i < screenHeight; i += gridSize)
        //{
        //    DrawLine(0, i, screenWidth, i, gridColor);
        //}
        //// Draw vertical lines
        //for (int i = 0; i < screenWidth; i += gridSize)
        //{
        //    DrawLine(i, 0, i, screenHeight, gridColor);
        //}
        DrawTexture(mainCharacter, position.x, position.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
}
