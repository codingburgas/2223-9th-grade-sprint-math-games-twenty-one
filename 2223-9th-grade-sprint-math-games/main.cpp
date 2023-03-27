#include <iostream>
#include <raylib.h>
#include <stdlib.h>

//Include header files
#include "Mult.h"
#include "Convert.h"
#include "Substract.h"
#include "Addition.h"

using namespace std;


// Set up the screen parameters
const int screenWidth = 400.0;
const int screenHeight = 300.0;



//Move function
void move(Vector2 &position)
{
    //Move left
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        if(position.x > 0)
            position.x -= 8;
    }
    //Move right
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        if(position.x < screenWidth - 90)
            position.x += 8;
    }
    //Move up
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        if (position.y > 0)
            position.y -= 8;
    }
    //Move down
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        if(position.y < screenHeight - 75)
            position.y += 8;
    }
}


//Main function
int main()
{
    SetTargetFPS(60);

    //Set position for the character
    Vector2 position;
    position.x = 0;
    position.y = 0;
    //Initialize window
    InitWindow(screenWidth, screenHeight, "Binary King");

    //Load Textures and Images
    Texture2D mainCharacter = LoadTexture("images/binary_king.png");
    Image icon = LoadImage("images/icon.png");
    SetWindowIcon(icon);

    //Grid layout
    Rectangle rec[3][4];
    bool flagCon = false, flagMult = false, flagSub = false, flagAdd = false;
    const char* level[3][4] = {
    "-", "+", "C", "-",
    "x", "-", "+", "x",
    "-", "+", "C", "x",
    };

    //Initialize Numbers to be calculated
    unsigned int binNum[3][5] = {
    1, 10, 11, 100, 101,
    110, 111, 1000, 1001, 1010,
    1011, 1100, 1101, 1110, 1111 };


    //Main game loop
    while (!WindowShouldClose())
    {
        move(position);
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
    //Draw rectangle grid layout
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                rec[i][j] = {(float)j* screenWidth / 4,(float)i* screenHeight / 3,screenWidth / 4, screenHeight / 3 };
                DrawRectangleRec(rec[i][j], WHITE);
                DrawRectangleLinesEx(rec[i][j], 1, BLACK);
            }
        }
    //Draw mathematical symbols
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                DrawText(level[i][j], rec[i][j].x + (screenWidth / 4) / 2 - 15, rec[i][j].y + (screenHeight / 3) / 2 - 60 / 2, 60, BLUE);
            }
        }
        //Check if the enter key is pressed when over a symbol
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
                            flagSub = true;
                        }
                        else if (level[i][j] == "+")
                        {
                            flagAdd = true;
                        }
                        else if (level[i][j] == "x")
                        {
                            flagMult = true;
                        }
                        else if (level[i][j] == "C")
                        {
                            flagCon = true;
                        }
                    }
                }
            }
        }
        //Call functions for every different level
        if (flagMult)
        {
            multGame();
            flagMult = false;
        }
        if (flagSub)
        {
            subGame();
            flagSub = false;
        }
        if (flagCon)
        {
            conGame();
            flagCon = false;
        }
        if (flagAdd)
        {
            addGame();
            flagAdd = false;
        }

        DrawTexture(mainCharacter, position.x, position.y, WHITE);
        EndDrawing();
    }
    //Unload Textures and close window
    UnloadTexture(mainCharacter);
    CloseWindow();
}
