//File Name: Assign7Ch5Proj4.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 7 Chapter 5 Project 4
//Description:
//Last Date Changed: 10/13/2022

#include <iostream>
using namespace std;

//Declare all global constants
const int QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1, CENT_MIN = 1, CENT_MAX = 99;

void getInput(int& cents);
//Get the input from the user
//I:cents variable
//O:N/A

void computeCoins(int& cents, int& q, int& d, int& n, int& p);
//Calculate and output the number of each coin needed to bring cents down to min possible
//I:We take in cents and the 4 variables
//O:N/A

void calculateCoins(int& cents, int& q, int& d, int& n, int& p);
//Call on the computeCoins() function until pennies equals 0
//I:cents, number of quarters, dimes, nickels, and pennies
//O:N/A

void outPut(int& q, int& d, int& n, int& p);
//Output the change in coins
//I:The number of each coin that we've calculated
//O:N/A

int main()
{
    //Declare variables we'll be using in main program
    char ans;
    int cents;

    //Allow user to repeat and end loop at the end of each iteration
    do
    {
        //Declare and initialize variables for the repeating function of the main program
        int numQuarters = 0, numDimes = 0, numNickels = 0, numPennies = 0;

        //Prompt user for input
        getInput(cents);

        //Perform calculations
        calculateCoins(cents, numQuarters, numDimes, numNickels, numPennies);

        //Output the change
        outPut(numQuarters, numDimes, numNickels, numPennies);

        //Prompt user if they want to repeat the loop
        cout << "Do you want to rerun the program? Y for yes N for no:\n";
        cin >> ans;
    }while(tolower(ans) == 'y');

    //Exiting message to end the main program
    cout << "Goodbye and have a good day! :)\n";
    return 0;
}

void getInput(int& cents)
{
    do
    {
        cout << "Enter the amount of cents:\n";
        cin >> cents;
    }while(cents < CENT_MIN || cents > CENT_MAX);
}

void computeCoins(int& cents, int& q, int& d, int& n, int& p)
{
    //Check for the coins that you can
   if(cents >= QUARTER)
   {
       cents -= QUARTER;
       q++;
   }
   else if(cents >= DIME)
   {
       cents -= DIME;
       d++;
   }
   else if(cents >= NICKEL)
   {
       cents -= NICKEL;
       n++;
   }
   else if(cents >= PENNY)
   {
       cents -= PENNY;
       p++;
   }
}

void calculateCoins(int& cents, int& q, int& d, int& n, int& p)
{
    //Call on compute until we get all coins
    while(cents != 0)
    {
        computeCoins(cents, q, d, n, p);
    }
}

void outPut(int& q, int& d, int& n, int& p)
{
    cout << "The change in coins is " << q << " quarters, " << d << " dimes, " << n << " nickels, and " << p << " pennies.\n";
}

/*Sample Run:
 * Enter the amount of cents:
45
The change in coins is 1 quarters, 2 dimes, 0 nickels, and 0 pennies.
Do you want to rerun the program? Y for yes N for no:
y
Enter the amount of cents:
100
Enter the amount of cents:
-2
Enter the amount of cents:
57
The change in coins is 2 quarters, 0 dimes, 1 nickels, and 2 pennies.
Do you want to rerun the program? Y for yes N for no:
n
Goodbye and have a good day! :)

 */