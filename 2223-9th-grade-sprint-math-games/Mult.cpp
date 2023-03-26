#include <iostream>
#include <raylib.h>
#include <stdlib.h>
using namespace std;


//Include header files
#include "Addition.h"
#include "Main.h"


//Initialize Numbers to be calculated
const int binNum[15] = 
{
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 
};


//Function for multiplying
void multGame()
{
    system("CLS");
    int firstRandomNum = binNum[GetRandomValue(0, 15)];
    int secondRandomNum = binNum[GetRandomValue(0, 15)];
    cout << "\nWelcome! Now you have to multiply the first binary number that you see with the second one on your screen!" << endl;
    cout << "Input your answear after the equals sign." << endl;

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
            result = additionNums(firstRandomNum, result);
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