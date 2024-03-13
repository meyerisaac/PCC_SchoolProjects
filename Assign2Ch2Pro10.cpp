//Assign2Ch2Pro10.cpp
//Isaac Meyer
//imeyer@go.pasadena.edu
//Assignment: 2
//Description:
//Last Changed: September 8, 2022

#include <iostream>
#include <string>
using namespace std;


int main()
{
    //Declaring all variables that will be used in the entire program
    char ans;
    int posSum, posAverage, negSum, negAverage, totalSum, totalAverage, count, num;
    const int NUM_INPUTS = 10;

    do
    {
        //Reset all variables to default if the code is rerun again
        posSum = 0;
        posAverage = 0;
        negSum = 0;
        negAverage = 0;
        totalSum = 0;
        totalAverage = 0;
        count = 1;

        //Create a loop that repeats ten times which is what the const is currently set to
        while(count <= NUM_INPUTS)
        {
            //Reset var 'num' as 0 at the start of each loop
            num = 0;

            //Prompt user to enter a number
            cout << "Enter a number:";
            cin >> num;

            //Add to positive or negative sum, then add to the total sum
            if(num > 0)
            {
                posSum += num;
            }
            if(num < 0)
            {
                negSum += num;
            }
            totalSum += num;

            //Calculate the averages for all the sums
            posAverage = posSum / count;
            negAverage = negSum / count;
            totalAverage = totalSum / count;

            //Increase loop counter by 1
            count++;
        }

        //Display all sums and averages to the user
        cout << "The positive sum is " << posSum << endl;
        cout << "The negative sum is " << negSum << endl;
        cout << "The total sum is " << totalSum << endl;

        cout << "The average of all the positive integers is " << posAverage << endl;
        cout << "The average of all the negative integers is " << negAverage << endl;
        cout << "The average of all the integers is " << totalAverage << endl;

        //Prompt user to repeat or end program
        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";

    return 0;
}

/*
Enter a number:2
Enter a number:4
Enter a number:6
Enter a number:-4
Enter a number:-46
Enter a number:67
Enter a number:-28
Enter a number:3
Enter a number:4
Enter a number:3
The positive sum is 89
The negative sum is -78
The total sum is 11
The average of all the positive integers is 8
The average of all the negative integers is -7
The average of all the integers is 1
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye
 */

