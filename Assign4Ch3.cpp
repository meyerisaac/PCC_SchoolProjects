//Fie Name: Assign4Ch3.cpp
//Author: Isaac Meyer
//Email Address: imeyer@go.pasadena.edu
//Assignment: Assignment 4 Chapter 3 Project 8
//Description: We take the number of terms that the user would want for the approximation of pi as an input and use that to calculate the approximation
//Then we output this approximation to the user at the end of the program before prompting if the user would like to run the program again
//Last Date Changed: 09/22/2022

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    //Declare variables
    char ans;
    int numCounter, numTerms;
    double denominator, numerator, tempOut, endOut;
    const int MULTIPLY_SUM = 4, DOUBLE_NUM = 2, NEG_ONE = -1, POS_ONE = 1;
    bool inputVal;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);

    do
    {
        //Initializing the variables
        inputVal = false;
        endOut = 0;

        //Repeat this loop until we get a valid input
        while(!inputVal)
        {
            cout << "Enter the number of terms for approximation of pi: ";
            cin >> numTerms;

            if(numTerms > 0)
            {
                inputVal = true;
            }
        }

        //Repeat loop until we reach number of desired terms
        for(numCounter = 0; numCounter < numTerms + 1; numCounter++)
        {
            //Assigning a positive or negative value to the numerator
            if(numCounter % 2 == 0)
            {
                numerator = POS_ONE;
            }
            else if(numCounter % 2 != 0)
            {
                numerator = NEG_ONE;
            }

            //Calculate the value for the denominator
            denominator = (DOUBLE_NUM * numCounter) + POS_ONE;

            //Update the value of our output variable
            tempOut = MULTIPLY_SUM * (numerator / denominator);
            endOut += tempOut;
        }

        //Output the approximation
        cout << "Your approximation of pi comes to " << endOut << endl;

        //Ask user if they want to repeat
        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(tolower(ans) == 'y');

    cout << "Good-Bye\n";

    return 0;
}
