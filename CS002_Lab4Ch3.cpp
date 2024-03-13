//File Name:Lab4Ch3.cpp
//Author: Isaac Meyer & James Donckels
//Email Address:imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment:Lab 4 Chapter 3 Project 11
//Description: Calculate desired temperature based on the inputted temperature
//Last Date Changed: 09/20/2022

#include <iostream>
using namespace std;

int main()
{
    //Declare variables
    char ans;
    int inputVar, minOut = 0, maxOut = 0, hundredthsPlace, tensPlace, onesPlace, placeHolder;
    bool ifLegal;
    const int ILLEGAL1 = 1;
    const int ILLEGAL2 = 4;
    const int ILLEGAL3 = 7;
    const int MAX_TEMP = 999;
    const int MIN_TEMP = 0;

    //Repeat the program if the user would like to
    do
    {
        //Get a valid input temperature from the user
        do
        {
            cout << "Enter temperature in degrees between 0 - 999:";
            cin >> inputVar;
        }while(inputVar < MIN_TEMP || inputVar > MAX_TEMP);

        //The calculations to place all the correct values into their correct variables
        hundredthsPlace = inputVar / 100;
        placeHolder = inputVar - (hundredthsPlace * 100);
        tensPlace = placeHolder / 10;
        placeHolder = placeHolder - (tensPlace * 10);
        onesPlace = placeHolder;
        //cout << hundredthsPlace << tensPlace << onesPlace; test statement

        //Scan through all the places from hundreds to ones
        //If illegal number, then create a smaller and bigger number and assign to respective output variable
        //If contains illegal number set ifLegal to false and vice versa for true
        if((hundredthsPlace == ILLEGAL1) || (hundredthsPlace == ILLEGAL2) || (hundredthsPlace == ILLEGAL3))
        {
            maxOut = (hundredthsPlace + 1) * 100;
            minOut = ((hundredthsPlace - 1) * 100) + 99;

            ifLegal = false;
        }
        else if((tensPlace == ILLEGAL1) || (tensPlace == ILLEGAL2) || (tensPlace == ILLEGAL3))
        {
            maxOut = (hundredthsPlace * 100) + ((tensPlace + 1) * 10);
            minOut = (hundredthsPlace * 100) + ((tensPlace - 1) * 10) + 9;

            ifLegal = false;
        }
        else if((onesPlace == ILLEGAL1) || (onesPlace == ILLEGAL2) || (onesPlace == ILLEGAL3))
        {
            maxOut = (hundredthsPlace * 100) + (tensPlace * 10) + (onesPlace + 1);
            minOut = (hundredthsPlace * 100) + (tensPlace * 10) + (onesPlace - 1);

            ifLegal = false;
        }
        else
        {
            ifLegal = true;
        }

        //Based on ifLegal, we'll output the original temperature or the 2 new ones
        if(ifLegal)
        {
            cout << "\nYour desired temp is: " << inputVar << endl;
        }
        else
        {
            cout << "\nYour desired temperatures are: " << maxOut << " and " << minOut << endl;
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
/* Sample Run
Enter temperature in degrees between 0 - 999:-5
Enter temperature in degrees between 0 - 999:1000
Enter temperature in degrees between 0 - 999:500

Your desired temp is: 500
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:y
Enter temperature in degrees between 0 - 999:450

Your desired temperatures are: 500 and 399
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:y
Enter temperature in degrees between 0 - 999:375

Your desired temperatures are: 380 and 369
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye
 */
