//File Name: Lab12Ch7Proj1.cpp
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 12 Chapter 7 Project 1
//Description:
//Last Date Changed: 11/17/2022

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

double findMax(double arr[], int size);
//Find the max value in the array
//I:The array we’re searching through
//O:The maximum value in the array

double scaleRate(double rate, double maxDiff);
//A quick function to calculate the scaling rate that we'll be using

string getMonth(int num);
//Return a string of the month based on the given integer

void getInput(string names[], double actual[], double average[]);
//Get input from the input file and put them into their respective arrays
//I:Takes in all the arrays
//O:No outputs, but the arrays leave the function with all their indexes assigned their respective values

void getDiff(double diff[], double actual[], double average[], double size);
//Calculate the differences for each respective index using the actual and average arrays
//I:Takes in all the arrays and the size of the arrays
//O:No outputs, but the diff array will have the differences for all the corresponding values in the actual
//and average arrays

string drawGraph(double numStars);
//Function to draw the stars with their corresponding spaces
//I:Takes in the number of stars that should be drawn along with whether it's negative or positive
//O:Outputs the visual representation for the number of stars as a string

//Declare the global constant variables
const int NUM_ROWS = 12, SCALE_RATE = 10, WIDTH = 15;

int main()
{
    char ans = 'y';

    //Prompt user to rerun the program
    while(tolower(ans) == 'y')
    {
        //Declare all the strings, variables, and arrays we'll be using
        string names[NUM_ROWS];
        double actual[NUM_ROWS];
        double average[NUM_ROWS];
        double difference[NUM_ROWS];
        double actualMax, averageMax, diffMax, scalingRate;
        char space = ' ';

        //Open output stream to write onto it
        ofstream fout("outfile.txt");

        //Processing
        getInput(names, actual, average);
        getDiff(difference, actual, average, NUM_ROWS);
        actualMax = findMax(actual, NUM_ROWS);
        averageMax = findMax(average, NUM_ROWS);
        diffMax = findMax(difference, NUM_ROWS);
        scalingRate = scaleRate(SCALE_RATE, diffMax);

        //Output
        fout << setw(WIDTH) << "Month" << setw(WIDTH) << "Actual" << setw(WIDTH) << "Average" << setw(WIDTH) << "Difference" << setw(WIDTH) << "Graph" << endl;
        fout << setw(WIDTH) << "Maximum" << setw(WIDTH) << actualMax << setw(WIDTH) << averageMax << setw(WIDTH) << diffMax << setw(WIDTH) << "Maximum" << endl;
        fout.setf(ios::right);
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        //Loop every line for every element in the arrays
        for(int i = 0; i < NUM_ROWS; i++)
        {
            fout << setw(WIDTH) << names[i] << setw(WIDTH);
            fout << actual[i] << setw(WIDTH);
            fout << average[i] << setw(WIDTH);
            fout << difference[i] << setw(WIDTH);
            fout << drawGraph(difference[i] * scalingRate);
            fout << endl;
        }

        //Close the output file
        fout.close();

        //Let the user know that the file output is done
        cout << "Output file done\n";

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

double findMax(double arr[], int size)
{
    //Set the precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Find the maximum value
    double max = abs(arr[0]);
    for(int i = 0; i < size; i++)
    {
        if(abs(arr[i]) > abs(max))
        {
            max = arr[i];
        }
    }
    return max;
}

double scaleRate(double rate, double maxDiff)
{
    //Calculate the scaling rate
    double out = rate / maxDiff;
    return out;
}

string getMonth(int num)
{
    //Convert the number to a corresponding month
    switch(num)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            cout << "Error Month Conversion Switch Case\n";
            exit(1);
    }
}

void getInput(string names[], double actual[], double average[])
{
    //Open the input file and validate it
    ifstream fin("rainfall averages.txt");
    if(fin.fail())
    {
        cout << "getInput() file input stream failed!\n";
        exit(1);
    }

    //Set the precision for the numbers
    fin.setf(ios::fixed);
    fin.setf(ios::showpoint);
    fin.precision(2);

    //Declare the variables
    int index;
    double value;

    //Loop until the end of file
    while(!fin.eof())
    {
        //Convert the data file into the months, actual, and average arrays
        fin >> index;
        names[index - 1] = getMonth(index);
        fin >> value;
        actual[index - 1] = value;
        fin >> value;
        average[index - 1] = value;
    }
}

void getDiff(double diff[], double actual[], double average[], double size)
{
    //Calculate the differences array
    for(int i = 0; i < size; i++)
    {
        diff[i] = actual[i] - average[i];
    }
}

string drawGraph(double numStars)
{
    //Declare the variables we'll be using
    signed int num;
    string out = "";

    //Find out if the number should be rounded up or down
    if(numStars >= 0)
    {
        if((numStars - floor(numStars)) >= 0.5)
        {
            num = floor(numStars) + 1;
        }
        else
        {
            num = numStars;
        }
    }
    else
    {
        if(abs((numStars - ceil(numStars))) >= 0.5)
        {
            num = floor(numStars);
        }
        else
        {
            num = numStars + 1;
        }
    }

    //Create the correct visuals for the stars based on the number we calculated above
    if(num == 0)
    {
        out =  "          0          ";
    }
    else if(num > 0)
    {
        out = "          0";
        for(int i = 0; i < num; i++)
        {
            out += '*';
        }
        for(int i = 0; i < (SCALE_RATE - num); i++)
        {
            out += ' ';
        }
    }
    else if(num < 0)
    {
        num = abs(num);
        for(int i = 0; i < (SCALE_RATE - num); i++)
        {
            out += ' ';
        }
        for(int i = 0; i < num; i++)
        {
            out += '*';
        }
        out += "0          ";
    }

    //Return the generated visual
    return out;
}

/*Sample Run:
 * Output file done
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0
 */