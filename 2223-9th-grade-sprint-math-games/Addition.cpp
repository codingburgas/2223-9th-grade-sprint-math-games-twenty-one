#include <iostream>
#include <raylib.h>
#include <stdlib.h>
using namespace std;

#include "Main.h"

//Initialize Numbers to be calculated
const int binNum[15] = {
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 
};



int additionNums(int binary1, int binary2)
{
    int i = 0, remainder = 0, sum[20];
    int result = 0;

    while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    while (i >= 0)
        result = result * 10 + sum[i--];
    return result;
}



void addGame()
{
    system("CLS");
    int num1 = binNum[GetRandomValue(0, 15)];
    int num2 = binNum[GetRandomValue(0, 15)];
    cout << "Welcome to addition! Enter your answear: " << endl;
    cout << num1 << " + " << num2 << " = ";
    int input;
    cin >> input;
    if (additionNums(num1, num2) == input)
    {
        cout << "The answear is correct!" << endl;
    }
    else
    {
        cout << "The answear is incorrect! Try again!" << endl;
        addGame();
    }
}
