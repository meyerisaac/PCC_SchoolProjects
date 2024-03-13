//File: Assign3Ch3Pro1.cpp
//Author: Isaac Meyer
//Email Address: imeyer@go.pasadena.edu
//Assignment: Assignment 3 Chapter 3 Program 1
//Description: Calculate the cost of the
//Last Date Changed: 09/15/2022

#include <iostream>
using namespace std;

int main() {
    //Declaring all variable needed
    int timeHour, timeMinute, lengthCall;
    double costCall;
    char ans, day1, day2;
    char colon = ':';
    bool weekday, dayValid, timeValid, lengthValid = false;
    const double WEEKDAY_RATE = 0.40;
    const double WEEKNIGHT_RATE = 0.25;
    const double WEEKEND_RATE = 0.15;

    //Setting precision point of doubles to 2 decimals
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Repeat program upon user input
    do {
        //Resetting this variable back to 0 at start of each loop
        lengthCall = 0, costCall = 0;
        dayValid = false, timeValid = false;
        ans = 0;

        //Prompt user for day of week
        while (!dayValid) {
            cout << "Enter the first 2 letters of the day of the week:";
            cin >> day1 >> day2;

            //Use switch to tell between weekday and weekends using bool weekday
            switch (day1) {
                case 'M':
                case 'm':
                    if (day2 == 'O' || day2 == 'o') {
                        weekday = true;
                        dayValid = true;
                    }
                    break;
                case 'T':
                case 't':
                    if (day2 == 'U' || day2 == 'u' || day2 == 'H' || day2 == 'h') {
                        weekday = true;
                        dayValid = true;
                    }
                    break;
                case 'W':
                case 'w':
                    if (day2 == 'E' || day2 == 'e') {
                        weekday = true;
                        dayValid = true;
                    }
                    break;
                case 'F':
                case 'f':
                    if (day2 == 'R' || day2 == 'r') {
                        weekday = true;
                        dayValid = true;
                    }
                    weekday = true;
                    break;
                case 'S':
                case 's':
                    if (day2 == 'A' || day2 == 'a' || day2 == 'U' || day2 == 'u') {
                        weekday = false;
                        dayValid = true;
                    }
                    break;
                default:
                    cout << "Error 001\n";
                    break;
            }
        }



        //Prompting user for valid start time of call
        while (!timeValid) {
            cout << "Enter the start time of call inputted as 13:30 format:";
            cin >> timeHour >> colon >> timeMinute;

            //Checking for input errors
            if ((timeHour >= 0 && timeHour <= 23) && (timeMinute >= 0 && timeMinute <= 60)) {
                timeValid = true;
            } else {
                //Emergency ejection because the program can't handle non-integers
                cout << "\nError 002\n";
                cout << "Emergency Eject, Program Only Accepts Numbers(13:30 format)\n";
                return 0;
            }
        }

        //Prompt user for valid lengthTime
        while (!lengthValid) {
            cout << "What was the length of the call in minutes:";
            cin >> lengthCall;

            if (lengthCall >= 0) {
                lengthValid = true;
            }
        }

        //All calculations will be done here
        if (!weekday) {
            costCall = WEEKEND_RATE * lengthCall;
        }
        if (weekday) {
            if ((timeHour >= 8) && (timeHour) <= 18) {
                costCall = WEEKDAY_RATE * lengthCall;
            } else {
                costCall = WEEKNIGHT_RATE * lengthCall;
            }
        } else {
            cout << "Error 003\n";
        }

        cout << "The cost of your call is $" << costCall << endl;

        cout << "Do you want to repeat the program? \n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";
    return 0;
}

/* Error Def:
 * Error 001: Something went wrong with the weekday switch
 * Error 002: Something is wrong with the inputted timeHour or timeMinute
 * Error 003: Something wrong with calculations at weekday = true
 * Error 004: Something wrong with calculation or between calculation and previous program
 *
 * Sample Run:
 * Enter the first 2 letters of the day of the week:tr
    Enter the first 2 letters of the day of the week:tu
    Enter the start time of call inputted as 13:30 format:0:30
    What was the length of the call in minutes:50
    The cost of your call is $12.50
    Do you want to repeat the program?
    Press Y for yes and N for no,
    and then press return:n
    Good-Bye

    Process finished with exit code 0
 */