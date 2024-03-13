//File Name: Lab10Ch6Proj2.cpp
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 10 Chapter 6 Project 2
//Description: We'll read a file with names and grades on them and add the average to the end of each to the end
//of each student's grade and output that into a new file
//Last Date Changed: 10/25/2022

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool ifInStreamOpen(ifstream& stream);
//Checks if the stream was able to open
//I:Take in the input stream
//O:Outputs true or false accordingly

bool ifOutStreamOpen(ofstream& stream);
//Check if the stream was able to open
//I:Takes in the output stream
//O:Outputs true or false accordingly

void transcribeFiles();
//Take the input file, calculate the averages, and add it on in the output file
//I:No inputs, just gradeBook.txt
//O:No outputs, just changing outputFile.txt

const int NUM_GRADES = 10;

int main()
{
    char ans = 'y';

    //Prompt if user wants to run function again
    while(tolower(ans) == 'y')
    {
        //Run the function
        transcribeFiles();

        cout << "Do you want to rerun the program? Y for yes / N for now:\n";
        cin >> ans;
    }

    return 0;
}

bool ifInStreamOpen(ifstream& stream)
{
    if(stream.fail())
    {
        cout << "inStream() failed\n";
        exit(1);
    }
}

bool ifOutStreamOpen(ofstream& stream)
{
    if(stream.fail())
    {
        cout << "outStream() failed\n";
        exit(1);
    }
}

void transcribeFiles()
{
    //Open and validate the streams
    ifstream inStream("gradeBook.txt");
    ifInStreamOpen(inStream);
    ofstream outStream("outputFile.txt");
    ifOutStreamOpen(outStream);

    //Runs until we reach the end of the program
    while(!inStream.eof())
    {
        //Declare the variables
        char space = ' ';
        string name;
        double grade, total = 0;

        //Get the last name
        inStream >> name;
        outStream << name << space;

        //Get the first name
        inStream >> name;
        outStream << name << space;

        //Loop for the grades NUM_GRADES times
        for(int i = 0; i < NUM_GRADES; i++)
        {
            inStream >> grade;
            outStream << grade << space;

            total += grade;
        }

        //Compute the average and add it into the file
        int average = total / NUM_GRADES;
        outStream << "Average Grade: " << average << endl;
    }

    //Close streams after we're done
    inStream.close();
    outStream.close();

    //Let user know the transcribing was successful
    cout << "File successfully transcribed with additions!\n";
}

/*Sample Run:
 * File successfully transcribed with additions!
Do you want to rerun the program? Y for yes / N for now:
y
File successfully transcribed with additions!
Do you want to rerun the program? Y for yes / N for now:
n

Process finished with exit code 0
 */