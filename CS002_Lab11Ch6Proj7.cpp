//File Name: Lab11Ch6Proj7.cpp
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 11 Chapter 6 Assignment 7
//Description: Program will output an answer to the user's question based on the number of responses in the
//txt file and the number of characters in the user inputted string
//Last Date Changed: 11/03/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool inStreamVal(ifstream& fin);
//Check if the file has been opened successfully
//I:Takes in the file
//O:Outputs true or false depending on the status of the stream opening

void askQuestion(string& question);
//Prompts user for a question and saves it onto a string variable

void getAnswer(ifstream& fin, string& userAns, string& output, int& num);
//Takes user-inputted string and retrieves the appropriate answer from the answer file
//Post-condition: string answer has the correct answer response and is ready to be outputted to the user

void output(string out);
//Prints the right answer to the screen

const int NUM_ANS = 8, NUM_CH = 18;

int main()
{
    char ans = 'y';
    int num = NUM_CH;

    while(tolower(ans) == 'y')
    {
        //Declare and initialize the variables
        string question, answer;
        ifstream inStream;

        //Get the user input
        askQuestion(question);

        //Compute the pawn
        getAnswer(inStream, question, answer, num);

        output(answer);

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }

    cout << "Goodbye and please have a good day!\n";

    return 0;
}

bool inStreamVal(ifstream& fin) {
    //If file opening fails, exit command
    if (fin.fail()) {
        cout << "Error Opening Stream!\n";
        exit(1);
    }
}

void askQuestion(string& question)
{
    cout << "What's your question?\n";
    getline(cin.ignore(1, '\n'), question);
}

void getAnswer(ifstream& fin, string& userAns, string& output, int& num)
{
    char next = 0;
    int numChar = 0, numOfAns = 0, temp = 0;

    fin.open("fortune.txt");
    inStreamVal(fin);

    numChar = userAns.length();
    numOfAns = numChar % NUM_ANS;

    do
    {

        do
        {

            getline(fin, output);
            fin >> next;
            if(numOfAns != 0)
            {
                temp++;
            }

            if(temp > NUM_ANS)
            {
                temp = 0;
            }

            if(temp == 0)
            {
                getline(fin, output);
                fin.close();

                int index = output.find("#N");
                if (index >= 0)
                {
                    output.replace(index, 2, to_string(num));
                }

                if(num == 0)
                {
                    num = NUM_CH;
                }


                num--;

                return;
            }
        }while(next != '\n' && temp != numOfAns - 1);

        fin.putback(next);

        getline(fin, output);
    }while(fin.eof());

    fin.close();
}

void output(string out)
{
    cout << out << endl;
}

/*Sample Run
 *What's your question?
What's going on?
I used to know the answer to that question, but I have forgotten it.
Do you want to rerun the program? Y for yes / N for no:
y
What's your question?
Why?
That question has puzzled philosophers for centuries.
Do you want to rerun the program? Y for yes / N for no:
n
Goodbye and please have a good day!

Process finished with exit code 0

 */