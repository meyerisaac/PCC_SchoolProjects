//File Name: Assign9Ch6Prog2.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 9 Chapter 6 Program 2
//Description: Calculate the average of the doubles stored in doubleRandomNumbers.dat
//Last Date Changed: 10/25/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool streamOpen(ifstream& stream);
//Check to make sure if the opening of the stream was successful
//I:We check the declared stream
//O:Outputs true or false accordingly

void computeAverage(ifstream& inStream, double& out);
//Computes the average of all the doubles in file
//I:Takes in the file’s data as input
//O:Outputs the average as a double

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
        computeAverage(inStream, out);

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

void computeAverage(ifstream& inStream, double& out)
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
    out = total / counter;

    //Close the stream
    inStream.close();
}

void output(double& out)
{
    //Output in the desired format
    cout << "The average is " << out << endl;
}

/*Sample Run:
 * The average is 50.60
Do you want to rerun the program? Y for yes / N for no:
y
The average is 50.60
Do you want to rerun the program? Y for yes / N for no:
y
The average is 50.60
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0

 */