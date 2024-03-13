//File: Lab5Ch3Pro13.cpp
//Author: Isaac Meyer
//Email Address: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 5 Chapter 3 Program 13
//Description: Calculate the address the Riddler is hinting at
//Last Date Changed: 09/20/2022

#include <iostream>
using namespace std;

int main()
{
    //Declare all variables we're using
    char ans;
    int thousandsPlace, hundredsPlace, tensPlace, onesPlace, tempNum;
    bool numDiff, timesThree, ifOdd, valSum, valOut = false;
    const int MAX_NUM = 9999, DIGIT_SUM = 27, TRIPLE = 3, GET_THOUSANDS = 1000, GET_HUNDREDS = 100, GET_TENS = 10, INCREMENT = 2;

    //Do while the user prompts for the program to run again
    do
    {
        //Reset variables we will be reusing
        int testNum = 1001;
        thousandsPlace = 0, hundredsPlace = 0, tensPlace = 0, onesPlace = 0, testNum = 0;

        //Repeat this loop until we find out 4 digit integer
        while(!valOut && testNum < MAX_NUM)
        {
            //Increment upon each loop
            testNum += INCREMENT;

            //Assign the values to the placeholders of each digit place
            tempNum = testNum;
            thousandsPlace = tempNum / GET_THOUSANDS;
            tempNum %= GET_THOUSANDS;
            hundredsPlace = tempNum / GET_HUNDREDS;
            tempNum %= GET_HUNDREDS;
            tensPlace = tempNum / GET_TENS;
            onesPlace = tempNum % GET_TENS;

            //Checking for the validity of the 4 conditions
            if(thousandsPlace == hundredsPlace || thousandsPlace == tensPlace || thousandsPlace == onesPlace || hundredsPlace == tensPlace || hundredsPlace == onesPlace || tensPlace == onesPlace)
            {
                numDiff = false;
            }
            else
            {
                numDiff = true;
            }

            if((tensPlace * TRIPLE) == thousandsPlace)
            {
                timesThree = true;
            }
            else
            {
                timesThree = false;
            }

            if((thousandsPlace + hundredsPlace + tensPlace + onesPlace) == DIGIT_SUM)
            {
                valSum = true;
            }
            else
            {
                valSum = false;
            }

            if((onesPlace % 2) == 0)
            {
                ifOdd = false;
            }
            else
            {
                ifOdd = true;
            }

            if(numDiff && timesThree && valSum && ifOdd)
            {
                valOut = true;
            }
            else
            {
                valOut = false;
            }

        }

        //Output the calculated digit
        cout << "The number is " << testNum << endl;

        //Ask user if they want to repeat the program
        cout << "Do you want to repeat the program? \n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;

    }while (ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";
    return 0;
}
