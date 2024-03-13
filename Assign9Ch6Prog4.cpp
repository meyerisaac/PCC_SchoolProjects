//File Name: Assign9Ch6Prog4.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 9 Chapter 6 Program 4
//Description: Calculate the standard deviation of the doubles in doubleRandomNumbers.dat
//Last Date Changed: 10/25/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<cmath>
using namespace std;

bool streamOpen(ifstream& stream);
//Check to make sure if the opening of the stream was successful
//I:We check the declared stream
//O:Outputs true or false accordingly

void computeAverage(ifstream& inStream, double& average);
//Computes the average of all the doubles in file
//I:Takes in the file’s data as input
//O:Outputs the average as a double

void computeStandDev(ifstream& inStream, double& out);
//Function will calculate the standard deviation
//I:Takes in the input stream and the reference of variable out
//O:N/A

void output(double& out);
//Output the average
//I:Takes in the value of out
//O:No output, just displays the average in the format I set

const int DOUBLE_PRECISION = 2;

int main()
{
    //Declare var for user to repeat
    char ans = 'y';

    //Set the precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(DOUBLE_PRECISION);

    //Loop program as long as user wants
    while(tolower(ans) == 'y')
    {
        //Declare out output var
        double out;

        //Declare the stream
        ifstream inStream;

        //Calculations
        computeStandDev(inStream, out);

        //Output
        output(out);

        //Prompt user to rerun the program
        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }

    return 0;
}

bool streamOpen(ifstream& stream)
{
    //Check if stream declaration failed
    if(stream.fail())
    {
        cout << "Input File Opening Failed\n";
        exit(1);
    }
}

void computeAverage(ifstream& inStream, double& average)
{
    //Declare variables
    double next, total = 0;
    int counter = 0;

    //Set the precision for the calculations
    inStream.setf(ios::fixed);
    inStream.setf(ios::showpoint);
    inStream.precision(DOUBLE_PRECISION);

    //Stream open validation
    streamOpen(inStream);

    //Open the stream
    inStream.open("doubleRandomNumbers.dat");

    //Keep adding the next double until there's no more
    while(inStream >> next)
    {
        total += next;
        counter++;
    }

    //Compute the average of the sum of all the doubles
    average = total / counter;

    //Close the stream
    inStream.close();
}

void computeStandDev(ifstream& inStream, double& out)
{
    //Declare variables
    double next, average, temp = 0;
    int counter = 0;

    //Run computeAverage() to get the average
    computeAverage(inStream, average);

    //Open the stream
    inStream.open("doubleRandomNumbers.dat");

    //Adding the squares of the differences until no more doubles
    while(inStream >> next)
    {
        temp += pow(average - next, 2);
        counter++;
    }

    //Calculations
    out = sqrt(temp / counter);

    inStream.close();
}

void output(double& out)
{
    //Output in the desired format
    cout << "The standard deviation is " << out << endl;
}

/*Sample Run:
 * The standard deviation is 28.24
Do you want to rerun the program? Y for yes / N for no:
y
The standard deviation is 28.24
Do you want to rerun the program? Y for yes / N for no:
y
The standard deviation is 28.24
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0
 */