#include <iostream>
#include <raylib.h>
using namespace std;


//Include header files
#include "Addition.h"
#include "Main.h"


//Initialize Numbers to be calculated
unsigned int binNum[3][5] = {
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 };



void multGame()
{

    int firstRandomNum = 0, secondRandomNum = 0;

    cout << "\nWelcome! Now you have multiply the first binary number that you see with the second one on your screen!" << endl;
    cout << "Input your answear after the equals sign." << endl;

    for (int i = GetRandomValue(0, 4); i < 3; i++)
    {
        for (int j = GetRandomValue(0, 4); j < 5; j++)
        {
            firstRandomNum = binNum[i][j];
            secondRandomNum = binNum[i][j - 1]; break;
        }
    }

    cout << firstRandomNum << " x " << secondRandomNum << " = ";
    int userInput;
    cin >> userInput;

    int result = 0, factor = 1;
    while (secondRandomNum != 0)
    {
        int digit = secondRandomNum % 10;
        if (digit == 1)
        {
            firstRandomNum = firstRandomNum * factor;
            result = addGame(firstRandomNum, result);
        }
        else
        {
            firstRandomNum = firstRandomNum * factor;
        }
        secondRandomNum = secondRandomNum / 10;
        factor = 10;
    }


    if (userInput == result)
    {
        cout << "Your answear is correct! Congratulations!" << endl;
    }
    else
    {
        cout << "The answear is incorrect! Try again!" << endl;
        multGame();
    }
}