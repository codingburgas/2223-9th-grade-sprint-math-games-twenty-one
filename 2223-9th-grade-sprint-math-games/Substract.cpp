#include <iostream>
#include <cmath>
#include <raylib.h>
#include <stdlib.h>
using namespace std;

const int binNum[15] = {
1, 10, 11, 100, 101,
110, 111, 1000, 1001, 1010,
1011, 1100, 1101, 1110, 1111 };


int decimal(int num)
{
    int rem, decimal = 0, i = 0;
    while (num > 0)
    {
        rem = num % 10;
        decimal = decimal + (rem * pow(2, i));
        i++;
        num /= 10;
    }
    return decimal;
}

int binary(int num)
{
    int rem;
    int binary = 0, i = 1;
    do
    {
        rem = num % 2;
        binary = binary + (i * rem);
        num = num / 2;
        i = i * 10;
    } while (num > 0);
    return binary;
}



void subGame()
{
    system("CLS");
    int binary1 = binNum[GetRandomValue(8, 15)];
    int binary2 = binNum[GetRandomValue(0, 7)];
    cout << "Welcome to substraction! Enter your answear: " << endl;
    cout << binary1 << " - " << binary2 << " = ";
    int input;
    cin >> input;



    int temp1, temp2, sub;
    int bin;
    temp1 = decimal(binary1);
    temp2 = decimal(binary2);
    sub = temp1 - temp2;
    bin = binary(sub);
    if (bin == input)
    {
        cout << "Congratulations!" << endl;
    }
    else
    {
        cout << "Your answer is incorrect! Try again!" << endl;
        system("pause");
        subGame();
    }
    cout << endl;
   
}