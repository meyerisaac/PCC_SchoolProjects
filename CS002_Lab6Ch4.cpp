//File Name: Lab6Ch4Proj4.cpp
//Author: Isaac Meyer & James Donckels
//Email Address: imeyer@go.pasadena.edu & 1jdonckels@go.pasadena.edu
//Assignment: Lab 5 Chapter 4
//Description: We are trying to get a menu item from the user and validate it before giving an output
//Last Date Changed: 09/27/2022

#include <iostream>
#include <cctype>
#include <cstring>
#include <ctype.h>
#include <string>
using namespace std;

int inputVal();
//Validate the input number

string numToString(int num);
//Convert a given number to string

string onesToString(int num);
//Convert the ones place to a string

string teensToString(int ones);
//Convert teen numbers to a string

string tensToString(int num);
//Convert tens place to a string

string out(string numWord1, string numWord2);
//The output for the program

string lower(string str);
//Convert a string to lowercase

int main()
{
    char ans;

    do
    {
        int input = inputVal();

        for(int count = input; count > 0; count--)
        {
            out(numToString(count), numToString(count - 1));
        }

        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(tolower(ans) == 'y');

    cout << "Good-Bye\n";

    return 0;
}

int inputVal()
{
    int temp;
    do
    {
    cout << "Enter number of bottles of milk: 1-99\n";
    cin >> temp;
    }while(temp < 1 || temp > 99);
    return temp;
}

string numToString(int num)
{
    int onesPlace, tensPlace;
    string subOut;
    char hyphen = '-';
    tensPlace = num / 10;
    onesPlace = num % 10;

    if(onesPlace == 0 && tensPlace == 0)
    {
        subOut = "Zero";
        return subOut;
    }
    else if(tensPlace == 0 && (onesPlace >= 0 && onesPlace <= 9))
    {
        subOut = onesToString(onesPlace);
        return subOut;
    }
    else if(tensPlace == 1 && onesPlace == 0)
    {
        subOut = "Ten";
        return subOut;
    }
    else if(tensPlace == 1 && (onesPlace >= 1 && onesPlace <= 9))
    {
        subOut = teensToString(onesPlace);
        return subOut;
    }
    else if((tensPlace >= 2 && tensPlace <= 9) && (onesPlace >= 1 && onesPlace <= 9))
    {
        subOut = tensToString(tensPlace) + hyphen + lower(onesToString(onesPlace));
        return subOut;
    }
}

string onesToString(int num)
{
    string tempString;

    switch(num)
    {
        case 1:
            tempString = "One";
            break;
        case 2:
            tempString = "Two";
            break;
        case 3:
            tempString = "Three";
            break;
        case 4:
            tempString = "Four";
            break;
        case 5:
            tempString = "Five";
            break;
        case 6:
            tempString = "Six";
            break;
        case 7:
            tempString = "Seven";
            break;
        case 8:
            tempString = "Eight";
            break;
        case 9:
            tempString = "Nine";
            break;
        default:
            cout << "Invalid01\n";
            break;
    }

    return tempString;
}

string teensToString(int ones)
{
    string tempString;

    switch(ones)
    {
        case 1:
            tempString = "Eleven";
            break;
        case 2:
            tempString = "Twelve";
            break;
        case 3:
            tempString = "Thirteen";
            break;
        case 4:
            tempString = "Fourteen";
            break;
        case 5:
            tempString = "Fifteen";
            break;
        case 6:
            tempString = "Sixteen";
            break;
        case 7:
            tempString = "Seventeen";
            break;
        case 8:
            tempString = "Eighteen";
            break;
        case 9:
            tempString = "Nineteen";
            break;
        default:
            cout << "Invalid02\n";
            break;
    }

    return tempString;
}

string tensToString(int num)
{
    switch(num)
    {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            cout << "Invalid03\n";
            break;
    }
}

string lower(string str)
{
    char firstLetter = static_cast<char>(tolower(str[0]));
    string restOfWord = str.substr(1,str.length());
    string newWord = firstLetter + restOfWord;
    return newWord;
}

string out(string numWord1, string numWord2)
{
    cout << numWord1
         << " bottles of beer on the wall,\n"
         << numWord1
         << " bottles of beer,\n"
         << "Take one down pass it around,\n"
         << numWord2
         << " bottles of beer on the wall.\n\n";
}