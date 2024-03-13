//File Name: Assign5Ch4Proj6.cpp
//Author: Isaac Meyer
//Email Address: imeyer@go.pasadena.edu
//Assignment: Assignment 5 Chapter 5 Project 6
//Description: We are trying to get a menu item from the user and loop a request for coin until the required amount is met.
//Last Date Changed: 09/30/2022

#include <iostream>
using namespace std;

const int NUMBER_OF_ITEMS = 4;
const double DOLLAR = 1.00, QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, COST_TWINKIE = 3.50, COST_GUM = 0.50, COST_CHIPS = 2.00;

int Menu();
//This function based on given input between 1 and NUMBER_OF_ITEMS and returns the respective return value

int DisplayMenu();
//This function will display the items

double twinkie();
//Runs if twinkie is chosen

double gum();
//Runs if gum is chosen

double chips();
//Runs if chips are chosen

int pay(double requiredCost);
//Runs until the amount is paid

int out(int item);
//Give output based on determined result

int main()
{
    using namespace std;
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    //Declare variable for
    char ans;

    do
    {
        //declare variable
        int optionNum;
        double requiredCost = 0;

        do
        {
            //Repeat the input request until the user exits out of the vending machine
            optionNum = Menu();
            switch(optionNum)
            {
                case 1:
                    //Twinkie selected
                    requiredCost = twinkie();
                    pay(requiredCost);
                    out(optionNum);
                    break;
                case 2:
                    //Gum selected
                    requiredCost = gum();
                    pay(requiredCost);
                    out(optionNum);
                    break;
                case 3:
                    //Chips selected
                    requiredCost = chips();
                    pay(requiredCost);
                    out(optionNum);
                    break;
                default:
                    //Option 4 selected
                    cout << "Exited\n";
                    break;
            }
        }while(optionNum != 4);

        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";

    return 0;
}

int Menu()
{
    //When Menu is activated, we will call display function
    using namespace std;
    int option = DisplayMenu();
}

int DisplayMenu()
{
    using namespace std;
    int num;

    //Repeat the function until an option is selected by the user
    do
    {
        cout << "Choose an option 1-4:\n"
                "1, Twinkie - $3.50\n"
                "2, Gum - $0.50\n"
                "3, Chips - $2.00\n"
                "4, Exit\n";
        cin >> num;
    }while(num < 1 || num > NUMBER_OF_ITEMS);
    return num;
}

double twinkie()
{
    //Output for twinkie selected
    using namespace std;
    cout << "Twinkie has been selected\n";

    return COST_TWINKIE;
}

double gum()
{
    //Output for gum selected
    using namespace std;
    cout << "Gum has been selected\n";

    return COST_GUM;
}

double chips()
{
    //Output for chips selected
    using namespace std;
    cout << "Chips has been selected\n";

    return COST_CHIPS;
}

int pay(double requiredCost)
{
    double tempVal = 0.00;
    char coin;

    //Repeat a request for a coin until the total due amount is paid
    do
    {
        cout << "Not Enough Paid(Current Pay $" << tempVal << " - Select a coin to pay:\n"
             "O - Dollar Coin\n"
             "Q - Quarter\n"
             "D - Dime\n"
             "N - Nickel\n";
        cin >> coin;

        switch(coin)
        {
            case 'O':
            case 'o':
                tempVal += DOLLAR;
                break;
            case 'Q':
            case 'q':
                tempVal += QUARTER;
                break;
            case 'D':
            case 'd':
                tempVal += DIME;
                break;
            case 'N':
            case 'n':
                tempVal += NICKEL;
                break;
            default:
                cout << "Invalid Coin\n\n";
                break;
        }
    }while(tempVal < requiredCost);

    if(tempVal == requiredCost)
    {
        cout << "Your change is $0\n";
        return true;
    }
    else if(tempVal > requiredCost)
    {
        cout << "Your change is $" << (tempVal - requiredCost) << endl;
        return false;
    }
    else
    {
        cout << "Error\n";
        return 0;
    }
}

int out(int item)
{
    //Output once an item is paid for
    switch(item)
    {
        case 1:
            cout << "Here is your twinkie!\n";
            break;
        case 2:
            cout << "Here is your gum!\n";
            break;
        case 3:
            cout << "Here are your chips!\n";
            break;
        default:
            cout << "Something went terribly wrong :'(\n";
            return 0;
    }
}