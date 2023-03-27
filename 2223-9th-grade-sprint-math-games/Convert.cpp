#include <iostream>
#include <raylib.h>
#include <cmath>
#include <stdlib.h>

using namespace std;
//Initialize Numbers to be calculated
const int binNum[15] = 
{
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 
};

//Function to convert numbers
void conGame()
{
    system("CLS");
    int userInput = 0;
    cout << "Welcome to the Convert level!" << endl;
    cout << "In this level you have to convert a binary number to a decimal number" << endl;
    int randomNum = binNum[GetRandomValue(0, 14)];
    cout << "The binary number that you have to convert is: " << randomNum << endl;
    cout << "Enter the number in decimal: ";
    cin >> userInput;
    int result = 0, counter = 0, remainder=0;

    //Algorthm for converting numbers
    while (randomNum != 0) {
        remainder = randomNum % 10;
        randomNum /= 10;
        result += remainder * pow(2, counter);
        ++counter;
    }

    if (result == userInput)
    {
        cout << "Your answer is correct" << endl;
    }
    else
    {
        cout << "You are incorrect! Try again!" << endl;
        system("pause");
        conGame();
    }

}
