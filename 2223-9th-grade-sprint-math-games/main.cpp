#include <iostream>
#include <raylib.h>

//Include header files
#include "Mult.h"
#include "Division.h"
#include "Substract.h"
#include "Addition.h"

using namespace std;


// Set up the screen parameters
float screenWidth = 400.0;
float screenHeight = 300.0;



//
//void multGame()
//{
//
//    int firstRandomNum = 0, secondRandomNum = 0;
//
//    cout << "\nWelcome! Now you have multiply the first binary number that you see with the second one on your screen!" << endl;
//    cout << "Input your answear after the equals sign." << endl;
//
//    for (int i = GetRandomValue(0, 4); i < 3; i++)
//    {
//        for (int j = GetRandomValue(0, 4); j < 5; j++)
//        {
//            firstRandomNum = binNum[i][j]; 
//            secondRandomNum = binNum[i][j - 1];break;
//        }    
//    }
//
//    cout << firstRandomNum << " x " << secondRandomNum << " = ";
//    int userInput;
//    cin >> userInput;
//
//    int result = 0, factor = 1;
//    while (secondRandomNum != 0)
//    {
//        int digit = secondRandomNum % 10;
//        if (digit == 1)
//        {
//            firstRandomNum = firstRandomNum * factor;
//            result = addGame(firstRandomNum, result);
//        }
//        else
//        {
//            firstRandomNum = firstRandomNum * factor;
//        }
//        secondRandomNum = secondRandomNum / 10;
//        factor = 10;
//    }
//
//
//    if (userInput == result)
//    {
//        cout << "Your answear is correct! Congratulations!" << endl;
//    }
//    else
//    {
//        cout << "The answear is incorrect! Try again!" << endl;
//        multGame();
//    }
//}
//
//void subGame()
//{
//    cout << "You are playing subGame" << endl;
//}
//
//int addGame(int binary1, int binary2)
//{
//    cout << "You are playing addition" << endl;
//    int i = 0, remainder = 0, sum[20];
//    int binaryprod = 0;
//
//    while (binary1 != 0 || binary2 != 0)
//    {
//        sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
//        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
//        binary1 = binary1 / 10;
//        binary2 = binary2 / 10;
//    }
//    if (remainder != 0)
//        sum[i++] = remainder;
//    --i;
//    while (i >= 0)
//        binaryprod = binaryprod * 10 + sum[i--];
//    return binaryprod;
//}
//
//void divGame()
//{
//    cout << "You are playing division" << endl;
//}

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
    InitWindow(screenWidth, screenHeight, "twenty-one");

    //Load Textures and Images
    Texture2D mainCharacter = LoadTexture("images/binary_king.png");
    Image icon = LoadImage("images/icon.png");
    SetWindowIcon(icon);

    //Grid layout
    Rectangle rec[3][4];
    bool flagDiv = false, flagMult = false, flagSub = false, flagAdd = false;
    const char* level[3][4] = {
    "-", "+", "/", "-",
    "x", "-", "+", "x",
    "-", "+", "/", "x",
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
                        else if (level[i][j] == "/")
                        {
                            flagDiv = true;
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
        if (flagDiv)
        {
            divGame();
            flagDiv = false;
        }
        if (flagAdd)
        {
            int num1 = 0, num2 = 0;
            for (int i = GetRandomValue(0, 4); i < 3; i++)
            {
                for (int j = GetRandomValue(0, 4); j < 5; j++)
                {
                    num1 = binNum[i][j];
                    num2 = binNum[i][j - 1]; break;
                }
            }
            cout << "Welcome to addition! Enter your answear: ";
            cout << num1 << " + " << num2 << " = " << endl;
                int input;
                cin >> input;
                if (addGame(num1, num2) == input)
                {
                    cout << "The answear is correct!";
                }
                else
                {
                    cout << "The answear is incorrect! Try again!";
                    flagAdd = true;
                }
            
            flagAdd = false;
        }

        DrawTexture(mainCharacter, position.x, position.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
}
