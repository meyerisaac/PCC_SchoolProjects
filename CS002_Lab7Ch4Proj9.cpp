//File Name: Lab7Ch4Proj9.cpp
//Author: Isaac Meyer & James Donckels

#include <iostream>
using namespace std;

int createRandNum1to40();
//This function will randomly generate a number from 1 to 40
//I:No inputs
//O:Outputs a number from 1 to 40

int selectTeam(int num);
//Given the generated number, it will assign number to a team
//I:Number generated
//O:Outputs the team number given the input

int pickTeam();
//Through generated number, select the first team
//I:No inputs
//O:Outputs the selected team

int pickTeam(int firstPick);
//Select the second team
//I:First picked team
//O:Outputs the second selected team

int pickTeam(int firstPick, int secondPick);
//Select the third team
//I:First and second picked teams
//O:Outputs the third selected team

int pickTeam(int firstPick, int secondPick, int thirdPick);
//Select the last team
//I:First, second, and third picked teams
//O:Outputs the last team

string displayTeamName(int num, string t1, string t2, string t3, string t4);
//Given the number of the selected team, we will output the specific team
//I:Number of team and the name of all the teams with their numbers.
//O:Output the team with the given number

const int MIN_RANGE = 1, MAX_RANGE = 40, MAX_ONE = 20, MAX_TWO = 30, MAX_THREE = 36, FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4;

int main()
{
    char ans;

    do
    {
        string t1, t2, t3, t4;
        int firstPick, secondPick, thirdPick, fourthPick;

        cout << "Enter name of first team:";
        cin >> t1;
        cout << "\nEnter name of second team:";
        cin >> t2;
        cout << "\nEnter name of third team:";
        cin >> t3;
        cout << "\nEnter name of fourth team:";
        cin >> t4;

        firstPick = pickTeam();
        secondPick = pickTeam(firstPick);
        thirdPick = pickTeam(firstPick, secondPick);
        fourthPick = pickTeam(firstPick, secondPick, thirdPick);

        cout << "The draft order is:"
             << displayTeamName(firstPick, t1, t2, t3,  t4) << ", "
             << displayTeamName(secondPick, t1, t2, t3, t4) << ", "
             << displayTeamName(thirdPick, t1, t2, t3, t4) << ", "
             << displayTeamName(fourthPick, t1, t2, t3, t4) <<".\n";

        cout << "Do you want to repeat the program?\nPress Y or y to continue\nPress anything else to stop\n";
        cin >> ans;
    }while(tolower(ans) == 'y');

    cout << "Goodbye!";
    return 0;
}

int createRandNum1to40()
{
    srand(time(0));
    return (rand() % 40) + 1;
}

int selectTeam(int num)
{
    if(num >= MIN_RANGE && num <= MAX_ONE)
    {
        return FIRST;
    }
    else if(num > MAX_ONE && num <= MAX_TWO)
    {
        return SECOND;
    }
    else if(num > MAX_TWO && num <= MAX_THREE)
    {
        return THIRD;
    }
    else if(num > MAX_THREE && num <= MAX_RANGE)
    {
        return FOURTH;
    }
    else
    {
        cout << "Error 001";
    }
}

int pickTeam()
{
    int num = selectTeam(createRandNum1to40());
    return num;
}

int pickTeam(int firstPick)
{
    int num = selectTeam(createRandNum1to40());
    while(num == firstPick)
    {
        num = selectTeam(createRandNum1to40());
    }
    return num;
}

int pickTeam(int firstPick, int secondPick)
{
    int num = selectTeam(createRandNum1to40());
    while(num == firstPick || num == secondPick)
    {
        num = selectTeam(createRandNum1to40());
    }
    return num;
}

int pickTeam(int firstPick, int secondPick, int thirdPick)
{
    int num = selectTeam(createRandNum1to40());
    while(num == firstPick || num == secondPick || num == thirdPick)
    {
        num = selectTeam(createRandNum1to40());
    }
    return num;
}

string displayTeamName(int num, string t1, string t2, string t3, string t4)
{
    switch(num)
    {
        case FIRST:
            return t1;
        case SECOND:
            return t2;
        case THIRD:
            return t3;
        case FOURTH:
            return t4;
    }
}

/*Sample Run:
 * Enter name of first team:Lion

Enter name of second team:Bear

Enter name of third team:Wolf

Enter name of fourth team:Tiger
The draft order is:Wolf, Tiger, Lion, Bear.
Do you want to repeat the program?
Press Y or y to continue
Press anything else to stop
y
Enter name of first team:Lion

Enter name of second team:Wolf

Enter name of third team:Tiger

Enter name of fourth team:Bear
The draft order is:Wolf, Tiger, Bear, Lion.
Do you want to repeat the program?
Press Y or y to continue
Press anything else to stop
n
Goodbye!
Process finished with exit code 0
 */