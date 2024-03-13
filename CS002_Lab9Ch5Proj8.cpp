//File Name: Lab9Ch5Proj8.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Lab 9 Chapter 5 Project 8
//Description: We'll ask the user for their birthdate and we will output the day of the week they were born, Jamal was born, and the current one
//Last Date Changed: 10/18/2022

#include <iostream>
#include <string>
using namespace std;

void getInput(int& day, int& month, int& year, int currDay, int currMonth, int currYear);
//We'll get the input from the user
//The ampersand variables will get the values that we give to them

void currentdate(int& currentDay, int& currentMonth, int& currentYear);
//Find the current date, that the program is running
//Will put the calculated values onto the call by reference values

bool isLeapYear(int year);
//Output true/false if the year falls under a leap year
//Takes in the year that we are checking

bool dayCheck(int day, int month, int year);
//Checks the day to make user it's within the range of it's respective month
//Returns true/false if the day is valid

int getCenturyValue(int year);
//Calculates a century value based on the year

int getYearValue(int year);
//Calculates a year value based on the year given

int getMonthValue(int month, int year);
//Calculate a month value based on the month and year given

bool inputVal(int day, int month, int year, int currDay, int currMonth, int currYear);
//Checks if the inputs is valid
//Will take in the inputted variables
//Outputs true/false based on if input is valid or not

int dayOfWeek(int day, int month, int year);
//Calculates the number corresponding the day of the week
//I:Takes in the date(date/month/year)
//O:Outputs the day number

string dateToDay(int date);
//Converts the day number to a string
//I:Takes in the int date
//O:Outputs a string that we got from the inputted date

void output(string currDayWeek, string dayWeek, string jamalDayWeek);
//Takes in the 3 ints from current day, the user's birth day, and jamal's birth day
//Outputs in correct format

//Declare the constants that we will be using
const int LEAP_FACTOR = 400, LEAP_DIVIDE = 4, CENTURY_FACTOR = 3, DOUBLE = 2, HUNDRED = 100, ZERO = 0, MONTHS = 12, MONTH_MIN = 30, MONTH_MAX = 31, FEB = 28, LEAP_FEB = 29, WEEKDAYS = 7;
const int JAMAL_DAY = 23, JAMAL_MONTH = 1, JAMAL_YEAR = 1960, MIN_YEAR_RANGE = 120;

int main()
{
    //Declare the variables we'll be using
    int currentDay, currentMonth, currentYear, day, month, year;
    currentdate(currentDay, currentMonth, currentYear);

    char userAns = 'y';

    //Allow user to repeat program and end as they wish
    while(tolower(userAns) == 'y')
    {
        //Grab the input from the user
        getInput(day, month, year, currentDay, currentMonth, currentYear);

        //Perform the calculations
        string dayWeek = dateToDay(dayOfWeek(day, month, year));
        string currDayWeek = dateToDay(dayOfWeek(currentDay, currentMonth, currentYear));
        string jamalDayWeek = dateToDay(dayOfWeek(JAMAL_DAY, JAMAL_MONTH, JAMAL_YEAR));

        //Display the output
        output(currDayWeek, dayWeek, jamalDayWeek);

        //Prompt user if they want to rerun the program
        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> userAns;
    }

    //Output message
    cout << "Goodbye and have an ok day\n";

    return 0;
}

void getInput(int& day, int& month, int& year, int currDay, int currMonth, int currYear)
{
    //Declare temp variables that we'll be using
    string temp;
    char comma = ',';

    //Repeat until valid input
    do
    {
        //Prompt user for input
        cout << "Enter your birthday in January 1, 2000 format:\n";
        cin >> temp >> day >> comma >> year;

        //Lowercase the entirety of the string
        for(int counter = ZERO; counter < temp.length(); counter ++)
        {
            temp[counter] = tolower(temp[counter]);
        }

        //Assign the int month it's value based on the string
        if(temp == "january")
        {
            month = 1;
        }
        else if(temp == "february")
        {
            month = 2;
        }
        else if(temp == "march")
        {
            month = 3;
        }
        else if(temp == "april")
        {
            month = 4;
        }
        else if(temp == "may")
        {
            month = 5;
        }
        else if(temp == "june")
        {
            month = 6;
        }
        else if(temp == "july")
        {
            month = 7;
        }
        else if(temp == "august")
        {
            month = 8;
        }
        else if(temp == "september")
        {
            month = 9;
        }
        else if(temp == "october")
        {
            month = 10;
        }
        else if(temp == "november")
        {
            month = 11;
        }
        else if(temp == "december")
        {
            month = 12;
        }
        else
        {
            month = ZERO;
        }

    }while(!inputVal(day, month, year, currDay, currMonth, currYear));
}

void currentdate(int& currentDay, int& currentMonth, int& currentYear)
{
    //Calculations for the current day's date
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    currentDay = now->tm_mday;
    currentMonth = (now->tm_mon + 1) ;
    currentYear = (now->tm_year + 1900) ;
}

bool isLeapYear(int year)
{
    //Check for the conditions of a leap year and return true/false
    if(year % LEAP_FACTOR == ZERO || ((year % LEAP_DIVIDE == ZERO) && (year % HUNDRED != ZERO)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dayCheck(int day, int month, int year)
{
    //Check for the number of days for each month
    switch(month)
    {
        case 1:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 2:
            if(isLeapYear(year))
            {
                if(day > ZERO && day <= LEAP_FEB)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(day > ZERO && day <= FEB)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        case 3:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 4:
            if(day > ZERO && day <= MONTH_MIN)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 5:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 6:
            if(day > ZERO && day <= MONTH_MIN)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 7:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 8:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 9:
            if(day > ZERO && day <= MONTH_MIN)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 10:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 11:
            if(day > ZERO && day <= MONTH_MIN)
            {
                return true;
            }
            else
            {
                return false;
            }
        case 12:
            if(day > ZERO && day <= MONTH_MAX)
            {
                return true;
            }
            else
            {
                return false;
            }
        default:
            cout << "Error001\n";
            return false;
    }
}

int getCenturyValue(int year)
{
    //Calculate century value
    int century = year / HUNDRED;
    return (CENTURY_FACTOR - (century % LEAP_DIVIDE)) * DOUBLE;
}

int getYearValue(int year)
{
    //Calculate year value
    int temp = year % HUNDRED;
    return (temp / LEAP_DIVIDE) + temp;
}

int getMonthValue(int month, int year)
{
    //Use month and if it is leap year to calculate month value
    switch(month)
    {
        case 1:
            if(isLeapYear(year))
            {
                return 6;
            }
            else
            {
                return 0;
            }
        case 2:
            if(isLeapYear(year))
            {
                return 2;
            }
            else
            {
                return 3;
            }
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
        default:
            cout << "Error001\n";
            break;
    }
}

bool inputVal(int day, int month, int year, int currDay, int currMonth, int currYear)
{
    //Check for all false conditions and if none are met, output true at the end
    if(month == ZERO)
    {
        cout << "Error002: Invalid Month Input\n";
        return false;
    }

    if(year > currYear)
    {
        cout << "Error003:Input Date Hasn't Happened Yet\n";
        return false;
    }
    if(year < currYear - MIN_YEAR_RANGE)
    {
        return false;
    }
    if(year == currYear)
    {
        if(month > currMonth)
        {
            return false;
        }
        else if(month == currMonth)
        {
            if(day > currDay)
            {
                return false;
            }
            if(day == currDay)
            {
                return false;
            }
        }
    }

    return dayCheck(day, month, year);
}

int dayOfWeek(int day, int month, int year)
{
    //Add the values of the calculations together
    int centuryVal = getCenturyValue(year);
    int yearVal = getYearValue(year);
    int monthVal = getMonthValue(month, year);

    //And perform the calculations to get the resulting int
    int sum = day + centuryVal + yearVal + monthVal;
    sum %= WEEKDAYS;

    //Return the result
    return sum;
}

string dateToDay(int date)
{
    //Based on given int, return the corresponding day's string
    switch(date)
    {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            cout << "Error004:Issue With Date To Day Conversion\n";
            break;
    }
}

void output(string currDayWeek, string dayWeek, string jamalDayWeek)
{
    //Output the results in the correct format
    cout << "Today's day is : " << currDayWeek << endl
         << "You were born on : " << dayWeek << endl
         << "Jamal was born on : " << jamalDayWeek << endl;
}

/*Sample Run:
 * Enter your birthday in January 1, 2000 format:
february 19, 2004
Today's day is : Tuesday
You were born on : Thursday
Jamal was born on : Saturday
Do you want to rerun the program? Y for yes / N for no:
y
Enter your birthday in January 1, 2000 format:
march 23, 235
Enter your birthday in January 1, 2000 format:
january 23, 1987
Today's day is : Tuesday
You were born on : Friday
Jamal was born on : Saturday
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0

 */