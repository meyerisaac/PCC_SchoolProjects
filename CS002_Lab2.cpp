#include <iostream>
#include <string>
using namespace std;
//Isaac Meyer Lab2 Chapter 2
//With James and Roberto

int main()
{
    char ans = 'y';
    int numExercises, loopCounter0;
    double totalPoints, totalPointsPossible, average;
    do
    {
        const double PERCENT = 100.00;
        numExercises = 0;
        totalPoints = 0;
        totalPointsPossible = 0;
        loopCounter0 = 1;
        average = 0;

        cout << "How many exercises will be inputted?" << endl;
        cin >> numExercises;

        while(numExercises > 0)
        {
            int points = 0, allPoints = 0;
            cout << "Points received for exercise " << loopCounter0 << ":" << endl;
            cin >> points;
            cout << "Total points possible for " << loopCounter0 << ":" << endl;
            cin >> allPoints;
            totalPointsPossible += allPoints;
            totalPoints += points;

            numExercises--;
            loopCounter0++;
        }

        average = (totalPoints / totalPointsPossible) * PERCENT;

        cout << "There are " << totalPoints << " points out of " << totalPointsPossible << " total points with a percentage of " << average << endl;

        cout << "Do you want to continue again? Press y for yes or n for no." << endl;
        cin >> ans;
    }while(ans == 'Y' || ans == 'y');

    return 0;
}
