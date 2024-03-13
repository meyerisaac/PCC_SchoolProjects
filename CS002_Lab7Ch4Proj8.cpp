//File Name:Lab7Ch4Proj8.cpp
//Author: Isaac Meyer & James Donckels
//Email Address:imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment:Lab 7 Chapter 4 Project 8
//Description: Calculate desired temperature based on the inputted temperature(with new boolean functions)
//Last Date Changed: 09/20/2022

#include <iostream>
using namespace std;

bool containsDigit(int number, int digit);
//This function will take in a number as well as an illegal digit, it will compare these 2 for illegal digits in the number
//I:Takes in inputted number and a given illegal digit
//O:Will return true or false for the given illegal digit

bool contains147(int number);
//This function will receive the given number and check if it contains any illegal numbers
//I:Takes in the inputted number
//O:Will return either true for true if illegal number if it is in there, and false for the reverse

const int ILLEGAL1 = 1;
const int ILLEGAL2 = 4;
const int ILLEGAL3 = 7;
const int MAX_TEMP = 999;
const int MIN_TEMP = 0;

int main()
{
    //Declare variables
    char ans;
    int inputVar, minOut = 0, maxOut = 0;
    bool ifLegal = true;


    //Repeat the program if the user would like to
    do
    {
        //Get a valid input temperature from the user
        do
        {
            cout << "Enter temperature in degrees between 0 - 999:";
            cin >> inputVar;
        }while(inputVar < MIN_TEMP || inputVar > MAX_TEMP);

        //Scan through all the places from hundreds to ones
        //If illegal number, then create a smaller and bigger number and assign to respective output variable
        //If contains illegal number set ifLegal to false and vice versa for true
        if(contains147(inputVar))
        {
            minOut = inputVar;
            while(contains147(minOut))
            {
                minOut--;
            }
            maxOut = inputVar;
            while(contains147(maxOut))
            {
                maxOut++;
            }
            cout << "\nYour desired temperatures are: " << maxOut << " and " << minOut << endl;
        }
        else
        {
            cout << "\nYour desired temp is: " << inputVar << endl;
        }

        //Prompt user to repeat the program
        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";

    return 0;
}

bool contains147(int number)
{
    return containsDigit(number, ILLEGAL1) ||
           containsDigit(number, ILLEGAL2) ||
           containsDigit(number, ILLEGAL3);
}

bool containsDigit(int number, int digit)
{
    int hundredthsPlace, tensPlace, onesPlace, placeHolder;
    //The calculations to place all the correct values into their correct variables
    hundredthsPlace = number / 100;
    placeHolder = number - (hundredthsPlace * 100);
    tensPlace = placeHolder / 10;
    placeHolder = placeHolder - (tensPlace * 10);
    onesPlace = placeHolder;
    //cout << hundredthsPlace << tensPlace << onesPlace; test statement

    if(hundredthsPlace == digit || tensPlace == digit || onesPlace == digit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Sample Run:
 * Enter temperature in degrees between 0 - 999:375

Your desired temperatures are: 380 and 369
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye

Process finished with exit code 0
 */