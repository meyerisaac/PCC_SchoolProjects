//File Name: Assign10Ch6Proj3.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 10 Chapter 6 Project 3
//Description: We'll read a file with names and grades on them and add the average to the end of each to the end
//of each student's grade and output that into a new file
//Last Date Changed: 10/25/2022

#include <iostream>
#include <iomanip>
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

const int NUM_GRADES = 10, LENGTH_LINE = 60;

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
    char space = ' ', next;
    ifstream inStream("gradeBook.txt");
    ifInStreamOpen(inStream);
    ofstream outStream("outputFile.txt");
    ifOutStreamOpen(outStream);

    string line(LENGTH_LINE,'-');
    string spaceLine(LENGTH_LINE / 3, space);

    //Format for the top and the descriptors
    outStream << line << endl << "Name" << spaceLine << "Score" << spaceLine << "Average" << endl << line << endl;

    //Runs until we reach the end of the program
    while(!inStream.eof())
    {
        int spaceCount = 0;
        //Repeat for each line
        while(inStream >> next && next != '\n')
        {
            //Put back the '\n' that we read
            inStream.putback(next);

            //Declare the variables
            double score, grade, total = 0;
            outStream.setf(ios::right);
            inStream >> next;

            if(!isdigit(next))
            {
                if(isspace(next))
                {
                    outStream << space;
                    spaceCount++;
                }
                outStream << next;
                spaceCount++;
            }
            else if(isdigit(next))
            {
                inStream.putback(next);
                outStream << space;

                for(int i = 0; i < NUM_GRADES; i++)
                {
                    inStream >> score;
                    outStream << score << space;
                    total += score;
                }

                //Compute the average and add it into the file
                int average = total / NUM_GRADES;
                string averageGap((NUM_GRADES / 3), space);
                outStream.setf(ios::left);
                outStream << averageGap << average << endl;
            }
        }
    }

    //Close streams after we're done
    inStream.close();
    outStream.close();

    //Let user know the transcribing was successful
    cout << "File successfully transcribed with additions!\n";
}

/*Sample File:
 * ------------------------------------------------------------
Name                    Score                    Average
------------------------------------------------------------
test_line_ 10 20 30 40 50 60 70 80 90 100    55
PriceBetty 40 50 60 70 60 50 40 30 60 90    55
GoodJohn 60 70 80 90 50 60 90 90 100 90    78
SmithCharles 70 80 90 60 70 60 80 90 90 90    78
SpangenbergWard 70 70 80 90 70 80 90 80 70 60    76
 */