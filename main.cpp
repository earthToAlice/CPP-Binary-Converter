#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*
    TODO:
    [DONE] Add prompt
    [DONE] Add conversion function w/ logic
    [DONE] Print conversion
    ------
    [DONE] Prompt for conversion type
    Add denary conversion logic
    Add input type validation
*/

int getConvType();
string toBinary();
int toDenary();
int getIntLength(unsigned long int input);

int main()
{
    switch (getConvType())
    {
        case 0:
            cout << toBinary();
            break;
        case 1:
            cout << toDenary();
            break;
    }

    return 0;
} //main()

int getConvType()
{
    int input;

    cout << "[0] to convert to binary" << endl;
    cout << "[1] to convert to denary" << endl;
    cin >> input;

    return input;
}

//function toBinary(). Prompts the user to enter a denary number and returns an equivalent binary string.
string toBinary()
{
    int input;

    cout << "Enter a number to convert to binary: ";
    cin >> input;
    string result = "";

    while (input >= 1)
    {
        if (input % 2 >= 1)
        {
            result = "1" + result;
        }
        else if (input % 2 < 1)
        {
            result = "0" + result;
        }

        input /= 2;
    }

    return result;
}

//function toDenary(). Prompts the user to enter a binary number and returns an equivalent denary int
int toDenary()
{
    unsigned long int input;
    int result = 0;
    int inputLength;

    cout << "Enter a number to convert to denary: ";
    cin >> input;
    inputLength = getIntLength(input);

    for (int i = 0; i < inputLength; i++)
    {
        if (input % 10 == 1) result += (int) pow(2, i);
        input /= 10;
    }
    
    return result;
}

//function getIntLength(unsigned long int input). Returns the number of digits in an unsigned long int (0-)
int getIntLength(unsigned long int input)
{
    if (input == 0) return 0;
    
    return 1 + getIntLength(input / 10);
}
