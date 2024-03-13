//File Name: Assign6Ch4Proj7.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assigment: Assignment 6 Chapter 4 Project 7
//Description: This program will calculate a time difference within 24 hours given any
//start time and end time
//Last Date Changed: 10/06/2022

#include <iostream>
using namespace std;

bool inputVal(int currHour, int currMin, int futureHour, int futureMin, char first1, char first2, char second1, char second2);
//This program will validate the inputs for us before we take them in as our value
//I:All the user inputted variables
//O:Outputs 'true' for valid and 'false' for invalid

int timeToMinutes(int hour, int minutes);
//This program will convert any given time to it's time in minutes
//I:Hour and Minute of the inputted time
//O:The Hour and Minute converted into minutes

bool isAM(char letter);
//Will confirm if it is day or night depending on the inputted char
//I:One char returned from the validateAMPM() function
//O:Return a boolean, true for day and false for night

bool diffTime(bool currIsAm, bool futureIsAm);
//Will let you know if the current and future times are the same am/pm
//I:ampm of current and future time
//O:True for if they are equal and false for if they are false

int difference(int futureHour, int futureMin, int currHour, int currMin);

int computeDifference(int currHour, int currMin, int futureHour, int futureMin, bool currIsAm, bool futureIsAm);

const int HOUR_MIN = 1, HOUR_MAX = 12, MIN_MIN = 0, MIN_MAX = 59;

int main()
{
    char ans, colon = ':';
    do
    {
        int inputCurrHour, inputCurrMin, inputFutureHour, inputFutureMin;
        char inputCurrAmPm1, inputCurrAmPm2, inputFutureAmPm1, inputFutureAmPm2;
        do
        {
            cout << "Enter the current time in 11:50 am format, a space, then followed by the future time:";
            cin >> inputCurrHour >> colon >> inputCurrMin >> inputCurrAmPm1 >> inputCurrAmPm2 >> inputFutureHour
                >> colon >> inputFutureMin >> inputFutureAmPm1 >> inputFutureAmPm2;
        }while(!inputVal(inputCurrHour, inputCurrMin, inputFutureHour, inputFutureMin, inputCurrAmPm1, inputCurrAmPm2, inputFutureAmPm1, inputFutureAmPm2));

        //Running our inputs through this program will give us the output
        int output = computeDifference(inputCurrHour, inputCurrMin, inputFutureHour, inputFutureMin, isAM(inputCurrAmPm2), isAM(inputFutureAmPm2));

        //Here we just output the output of our computeDifference function in the correct format
        cout << "The difference in minutes between the start and end time is " << output << " minutes.\n";

        cout << "Enter Y to rerun the program and any other button to stop:\n";
        cin >> ans;
    }while(tolower(ans) == 'y');

    return 0;
}

bool inputVal(int currHour, int currMin, int futureHour, int futureMin, char first1, char first2, char second1, char second2)
{
    if(currHour > HOUR_MAX || currHour < HOUR_MIN)
    {
        cout << "Error with input: CurrentTimeHour\n";
        return false;
    }
    else if(currMin > MIN_MAX || currMin < MIN_MIN)
    {
        cout << "Error with input: CurrentTimeMinute\n";
        return false;
    }
    else if(futureHour > HOUR_MAX || futureHour < HOUR_MIN)
    {
        cout << "Error with input: FutureTimeHour\n";
        return false;
    }
    else if(futureMin > MIN_MAX || futureMin < MIN_MIN)
    {
        cout << "Error with input: FutureTimeMinute\n";
        return false;
    }
    else if((tolower(first2) != 'm') || (tolower(second2) != 'm'))
    {
        cout << "Error with input: AmPmSecondLetter\n";
        return false;
    }
    else if(((tolower(first1) != 'a') && (tolower(first1) != 'p')) || ((tolower(second1) != 'a') && (tolower(second1) != 'p')))
    {
        cout << "Error with input: AmPmFirstLetter\n";
        return false;
    }
    else
    {
        return true;
    }
}

int timeToMinutes(int hour, int minutes)
{
    return (hour * 60) + minutes;
}

bool isAM(char letter)
{
    if(tolower(letter) == 'a')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool diffTime(bool currIsAm, bool futureIsAm)
{
    if(currIsAm == futureIsAm)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int computeDifference(int currHour, int currMin, int futureHour, int futureMin, bool currIsAm, bool futureIsAm)
{
    if(!diffTime(currIsAm, futureIsAm))
    {
        futureHour += 12;
        return difference(futureHour, futureMin, currHour, currMin);
    }
    else
    {
       if(futureHour < currHour)
        {
            futureHour += 24;
        }
        return difference(futureHour, futureMin, currHour, currMin);
    }
}

int difference(int futureHour, int futureMin, int currHour, int currMin)
{
    if(futureMin < currMin)
    {
        futureHour--;
        futureMin += 60;
    }
    return timeToMinutes((futureHour - currHour), (futureMin - currMin));
}

/*Sample Run:
 * Enter the current time in 11:50 am format, a space, then followed by the future time:13:30am 3:40pm
Error with input: CurrentTimeHour
Enter the current time in 11:50 am format, a space, then followed by the future time:10:70am 3:40pm
Error with input: CurrentTimeMinute

Enter the current time in 11:50 am format, a space, then followed by the future time:10:30zm 3:40pm
Error with input: AmPmFirstLetter
Enter the current time in 11:50 am format, a space, then followed by the future time:10:30am 15:40pm
Error with input: FutureTimeHour
Enter the current time in 11:50 am format, a space, then followed by the future time:10:30am 3:70pm
Error with input: FutureTimeMinute
Enter the current time in 11:50 am format, a space, then followed by the future time:10:30am 3:40zm
Error with input: AmPmFirstLetter
Enter the current time in 11:50 am format, a space, then followed by the future time:10:30am 3:40pm
The difference in minutes between t
he start and end time is 310 minutes.
Enter Y to rerun the program and any other button to stop:
n

Process finished with exit code 0
 */
