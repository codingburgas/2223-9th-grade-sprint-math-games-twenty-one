#include <iostream>
#include <raylib.h>

using namespace std;

// Set up the screen parameters
const int screenWidth = 400;
const int screenHeight = 300;


//Initialize Numbers to be calculated
unsigned int binNum[3][5] = {
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 };


void multGame()
{
    int firstRandomNum = 0, secondRandomNum = 0;
    //int multiply = 0, factor = 1;
    cout << "\nWelcome! Now you have multiply the first binary number that you see with the second one on your screen!" << endl;
    cout << "Input your answear after the equals sign." << endl;
    for (int i = GetRandomValue(0, 4); i < 3; i++)
    {
        for (int j = GetRandomValue(0, 4); j < 5; j++)
        {
            firstRandomNum = binNum[i][j]; 
            secondRandomNum = binNum[i][j - 1];break;
        }    
    }
    cout << firstRandomNum << " x " << secondRandomNum << " = ";
    int userInput;
    cin >> userInput;



    //while (secondRandomNum != 0)
    //{
    //    digit = secondRandomNum % 10;
    //    if (digit == 1)
    //    {
    //        firstRandomNum = firstRandomNum * factor;
    //        multiply = binaryproduct(firstRandomNum, multiply);
    //    }
    //    else
    //        binary1 = binary1 * factor;
    //    binary2 = binary2 / 10;
    //    factor = 10;
    //}

}

void subGame()
{

}

void addGame()
{

}

void divGame()
{

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
