#include <iostream>
#include <raylib.h>

using namespace std;

// Set up the screen parameters
const int screenWidth = 400;
const int screenHeight = 300;

void multGame()
{

    cout << "You are playing game mult game";
}

void subGame()
{
    cout << "You are playing sub";
}

void addGame()
{
    cout << "You are playing add";
}

void divGame()
{
    cout << "You are playing div";
}

//Move function
void move(Vector2 &position)
{
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        if(position.x > 0)
            position.x -= 10;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        if(position.x < screenWidth - 90)
            position.x += 10;
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        if (position.y > 0)
            position.y -= 10;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        if(position.y < screenHeight - 75)
            position.y += 10;
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

    //Rectangles
    Rectangle rec[3][4];
    bool flagDiv = false, flagMult = false, flagSub = false, flagAdd = false;
    //Main game loop
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
                        if (level[i][j] == "-")
                        {
                            subGame();
                        }
                        else if (level[i][j] == "+")
                        {
                            addGame();
                        }
                        else if (level[i][j] == "x")
                        {
                            multGame();
                        }
                        else if (level[i][j] == "/")
                        {
                            divGame();
                        }
                    }
                }
            }
        }

        DrawTexture(mainCharacter, position.x, position.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
}
