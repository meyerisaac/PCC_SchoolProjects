//File Name: Lab8Ch5Proj6.cpp
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 8 Chapter 6 Project 6
//Description: This program will run 1000(or however many we want) simulations of a duel between 3 people.
//Then it will tell us the probability of each of these three people winning in this duel under
//the conditions and rules that we have given them.
//Last Date Changed: 10/11/2022

#include <iostream>
#include <string>
using namespace std;

double findProb(int num);
//We will use this just to get the probability given a certain person
//I:Num of inputted person
//O:Probability of inputted person

void shoot(bool& target, double accuracy);
//Updates the inputted boolean depending on the result of the shot
//I:Boolean regarding the target's status and the accuracy of the person shooting
//O:No outputs, it will only update the boolean of the target

int startDuel(int& aaronMiss);
//This will run the simulation of the duel to give us a number representing the last man standing
//I:No inputs all the constants and needed information exists, we just need to run a simulation using that
//O:Number of the person that won

void output(double aaron, double bob, double charlie);
//This program will calculate the percentages and give us an output of the simulations
//I:Input the number of wins of the 3 people
//O:Outputs the probability of each person winning to the user

const int AARON = 1, BOB = 2, CHARLIE = 3, NUM_PEOPLE = 3, ONE = 1, HUNDRED = 100, THOUSAND = 1000;
const double AARON_PROB = 0.33, BOB_PROB = 0.50, CHARLIE_PROB = 1.00, HUN_DEC = 100.00;

int main()
{
    srand(time(0));
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    char ans, miss;
    int out, aaronMiss;


    do
    {
        double numBobWins = 0, numAaronWins = 0, numCharlieWins = 0;

        cout << "Do you want Aaron to miss his first shot? Y for yes N for no\n";
        cin >> miss;

        if(tolower(miss) == 'y')
        {
            aaronMiss = ONE;
        }
        else if(tolower(miss) != 'y')
        {
            aaronMiss = 0;
        }



        for(int counter = ONE; counter <= THOUSAND; counter++)
        {
            out = startDuel(aaronMiss);
            switch(out)
            {
                case 1:
                    numAaronWins++;
                    break;
                case 2:
                    numBobWins++;
                    break;
                case 3:
                    numCharlieWins++;
                    break;
                default:
                    cout << "Error004\n";
                    return 0;
            }
        }

        output(numAaronWins, numBobWins, numCharlieWins);

        cout << "Do you want to run the program again? Y for yes and N for no:";
        cin >> ans;
    }while(tolower(ans) == 'y');
    cout << "\nThank you and have a great day! :)\n";
    return 0;
}

double findProb(int num)
{
    switch(num)
    {
        case 1:
            return AARON_PROB;
        case 2:
            return BOB_PROB;
        case 3:
            return CHARLIE_PROB;
        default:
            cout << "Error001\n";
            return 0;
    }
}

void shoot(bool& target, double accuracy)
{
    int num = ((rand() % HUNDRED) + ONE);
    double result = num / HUN_DEC;
    if(result <= accuracy)
    {
        target = false;
    }
}

int startDuel(int& aaronMiss)
{
    //cout << "Loading..\n";
    int shooter = 0 + aaronMiss, tempOut = 0;
    int dead = 0;
    bool aaronAlive = true, bobAlive = true, charlieAlive = true;

    while(dead < 2)
    {
        if(aaronAlive)
        {
            dead++;
        }
        if(bobAlive)
        {
            dead++;
        }
        if(charlieAlive)
        {
            dead++;
        }
        
        shooter = (shooter % NUM_PEOPLE);
        switch(shooter + ONE)
        {
            case AARON:
                if(aaronAlive)
                {
                    if (charlieAlive)
                    {
                        shoot(charlieAlive, findProb(shooter + ONE));
                    }
                    else if (bobAlive)
                    {
                        shoot(bobAlive, findProb(shooter + ONE));
                    }
                }
                break;
            case BOB:
                if(bobAlive)
                {
                    if (charlieAlive)
                    {
                        shoot(charlieAlive, findProb(shooter + ONE));
                    }
                    else if (aaronAlive)
                    {
                        shoot(aaronAlive, findProb(shooter + ONE));
                    }
                }
                break;
            case CHARLIE:
                if(charlieAlive)
                {
                    if (bobAlive)
                    {
                        shoot(bobAlive, findProb(shooter + ONE));
                    }
                    else if (aaronAlive)
                    {
                        shoot(aaronAlive, findProb(shooter + ONE));
                    }
                }
                break;
            default:
                cout << "Error006\n";
                return 0;
        }

        shooter++;
        switch (shooter + ONE)
        {
            case 1:
                if(!aaronAlive)
                {
                    shooter++;
                }
                break;
            case 2:
                if(!bobAlive)
                {
                    shooter++;
                }
                break;
            case 3:
                if(!charlieAlive)
                {
                    shooter++;
                }
                break;
        }

        if(aaronAlive)
        {
            dead--;
        }
        if(bobAlive)
        {
            dead--;
        }
        if(charlieAlive)
        {
            dead--;
        }
    }
    if(aaronAlive)
    {
        tempOut = AARON;
    }
    else if(bobAlive)
    {
        tempOut = BOB;
    }
    else if(charlieAlive)
    {
        tempOut = CHARLIE;
    }
    else
    {
        cout << "Error 003\n";
    }
    return tempOut;
}

void output(double aaron, double bob, double charlie)
{
    cout << "\nThe probability of Aaron winning is " << (aaron / THOUSAND)
         << ", probability of Bob winning is " << (bob / THOUSAND)
         << ", and the probability of charlie winning is " << (charlie / THOUSAND)
         << endl;
}