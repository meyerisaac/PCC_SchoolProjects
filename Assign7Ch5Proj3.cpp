//File Name: Assign7Ch5Proj3.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Chapter 5 Assignment 7 Project 3
//Description: This program will ask for a starting time and a duration of time that you want to wait. Using
//these inputs, it will calculate the time that you will finish waiting as well as the current day
//and night status of that time.
//Last Date Changed: 10/13/2022

#include <iostream>
using namespace std;

void getInput(int& hours, int& min, bool& currIsAM);
//This function will be retrieving the current starting time(input validation included)
//I:Hours, Minutes, and Am/Pm of the time
//O:N/A

void getInput(int& hours, int& min);
//Prompts user to enter hours and minutes spent waiting(input validation included)
//I:Hours waiting and Minutes waiting
//O:N/A

void addMin(int& currMin, int& waitMin, int& currHour);
//Adds the minutes up and adjusts the hours accordingly
//I:Current Minute Time, Waiting Minutes, and Current Hour Time
//O:N/A

void addHour(int&currHour, int& waitHour, int& numAmPmSwitch);
//Adds the hours up and adjusts the AmPm accordingly
//I:Current Hour Time, Waiting Minute Time, Number of times ampm has flipped
//O:N/A

void ampmSwitch(bool& currIsAm, int& numAmPmSwitch);
//Switches the ampm accordingly
//I:Current ampm status and the number of times ampm will flip
//O:N/A

void outPut(int& currHour, int& currMin, bool& currIsAm);
//Will display the time after all the calculations have been performed
//I:Hour Time, Minute Time, and AmPm
//O:N/A

//Declaring our global constant values that we'll be reusing
const int MIN_HOUR = 1, MAX_HOUR = 12, MIN_MIN = 0, MAX_MIN = 59, HOUR = 60, EVEN = 2;

int main()
{
    //Declaring variables we'll be using in the main function
    char ans, addTime;
    int currHour, currMin, waitHour, waitMin;
    bool currIsAm;

    //We allow for the user to repeat and end the program
    do
    {
        //Prompt the user for a starting time
        getInput(currHour, currMin, currIsAm);

        //Loop in case the user wants to add more time to the calculated time
        do
        {
            //Set the number of times am/pm has switched so far to 0
            int numAmPmSwitch = 0;

            //Prompt user for waiting time
            getInput(waitHour, waitMin);

            //Perform all calculations
            addMin(currMin, waitMin, currHour);
            addHour(currHour, waitHour, numAmPmSwitch);
            ampmSwitch(currIsAm, numAmPmSwitch);

            //Display the output
            outPut(currHour, currMin, currIsAm);

            //Ask user if they want to add more time
            cout << "Do you want to add more time to the current time? Y for yes N for no:\n";
            cin >> addTime;
        }while(tolower(addTime) == 'y');

        //Ask user if they want to rerun the program
        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }while(tolower(ans) == 'y');
}

void getInput(int& hours, int& min, bool& currIsAm)
{
    //Declare local variables we'll be using
    char Am1, Am2, colon = ':';

    //Use input validation to make sure we get a valid input from the user
    do
    {
        cout << "Enter the starting time in 11:50pm format:\n";
        cin >> hours >> colon >> min >> Am1 >> Am2;
    }while (hours < MIN_HOUR || hours > MAX_HOUR || min < MIN_MIN || min > MAX_MIN || (tolower(Am2) != 'm') ||
            ((tolower(Am1) != 'a') && (tolower(Am1) != 'p')));
}

void getInput(int& hours, int& min)
{
    //Input validation to make sure we get a valid time in hours
    do
    {
        cout << "Enter the hours of waiting time:\n";
        cin >> hours;
    }while(hours < 0);

    //Input validation to make sure we get a valid time in minutes
    do
    {
        cout << "Enter the minutes of waiting time:\n";
        cin >> min;
    }while(min < 0);
}

void addMin(int& currMin, int& waitMin, int& currHour)
{
    //We add up the current and waiting minutes to get the total
    currMin += waitMin;

    //Set a counter to 0, so we can keep track of how many times we remove 60 minutes from our current time
    int countHour = 0;

    //Loop until our currMin is below 60 and becomes valid as an output
    while(currMin >= HOUR)
    {
        //Remove 60 minutes
        currMin -= HOUR;

        //Update for every iteration of this loop
        countHour++;
    }

    //Now we add the counter keeping track of how many hours we've removed from minutes
    currHour += countHour;
}

void addHour(int&currHour, int& waitHour, int& numAmPmSwitch)
{
    //First add up all the hours
    currHour += waitHour;

    //Loop until currHour is below the max hours on a clock
    while(currHour >= MAX_HOUR)
    {
        //Remove 12 hours from the current hour
        currHour -= MAX_HOUR;

        //Update the AmPmSwitch counter for every iteration of this loop
        numAmPmSwitch++;
    }
}

void ampmSwitch(bool& currIsAm, int& numAmPmSwitch)
{
    //Check if we need to change the AmPm of the time
    if(numAmPmSwitch % EVEN == 1)
    {
        //If AmPm has changed, we reverse the value of the currIsAm boolean
        if(currIsAm)
        {
            currIsAm = false;
        }
        else if(!currIsAm)
        {
            currIsAm = true;
        }
    }
    else if(numAmPmSwitch % EVEN == 0)
    {
        //If AmPm hasn't changed, we just return and change nothing
        return;
    }
}

void outPut(int& currHour, int& currMin, bool& currIsAm)
{
    //Declare variables for local use
    char colon = ':';

    //First we check if the output time is in am or pm
    if(currIsAm)
    {
        //We check if Min is below 9, so we can add our own 0 in front to maintain the 11:40pm format
        if(currMin >= MIN_MIN && currMin <= 9)
        {
            cout << "The time after waiting will be " << currHour << colon << "0" << currMin << "am\n";
        }
        else
        {
            cout << "The time after waiting will be " << currHour << colon << currMin << "am\n";
        }
    }
    else if(!currIsAm)
    {
        //We check if Min is below 9, so we can add out own 0 in front to maintain the 11:40pm format
        if(currMin >= MIN_MIN && currMin <= 9)
        {
            cout << "The time after waiting will be " << currHour << colon << "0" << currMin << "pm\n";
        }
        else
        {
            cout << "The time after waiting will be " << currHour << colon << currMin << "pm\n";
        }
    }
}

/*Sample Run:
Enter the starting time in 11:50pm format:
12:40pm
Enter the hours of waiting time:
2
Enter the minutes of waiting time:
40
The time after waiting will be 3:20am
Do you want to add more time to the current time? Y for yes N for no:
y
Enter the hours of waiting time:
2
Enter the minutes of waiting time:
40
The time after waiting will be 6:00am
Do you want to add more time to the current time? Y for yes N for no:
n
Do you want to rerun the program? Y for yes / N for no:
n
 */