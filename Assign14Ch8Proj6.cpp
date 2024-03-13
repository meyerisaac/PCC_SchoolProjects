//File Name: Assign14Ch8Proj6.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 14 Chapter 8 Project 6
//Description: This program will take a line string input from the user and replaces all the isolated integers with an equivalent series of 'x's
//Last Date Changed: 12/01/2022

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void getInput(string& in, bool& first);
//Get a line of input from the user
//I:Takes in a call by reference string
//O:No Outputs, will leave the string filled in

void encryptLine(string& line);
//Encrypts the integers in the line
//I:Takes in the call by reference string
//O:No Outputs, will encrypt the string

void out(string line);
//Outputs the string in desired format
//I:Takes in a string
//O:No Outputs, just displays the string

int main()
{
    //Declare variables
    char ans = 'y';

    while(tolower(ans) == 'y')
    {
        //Declare variables
        string line;
        bool first = true;

        //Input
        getInput(line, first);

        //Processes
        encryptLine(line);

        //Output
        out(line);

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void getInput(string& in, bool& first)
{
    //Prompt user for input and store it in string in
    cout << "Enter a line of input:\n";

    getline(cin.ignore(), in);
}

void encryptLine(string& line)
{
    //Check for all the isolated integers and replace them with an 'x'
    for(int places = 0; places < line.length(); places++)
    {
        if(isdigit(line[places]))
        {
            int counter, temp;
            for(counter = places; counter < line.length(); counter++)
            {
                temp = counter;
                if(((!isspace(line[counter - 1])) && (!isdigit(line[counter - 1]))) || (((!isspace(line[counter + 1]))) && (!isdigit(line[counter + 1]))))
                {
                    temp = line.length() + 1;
                    counter = line.length() + 1;
                }
                if(isspace(line[counter + 1]) || counter == line.length())
                {
                    temp = counter;
                    counter = line.length() + 1;
                }
            }
            counter = temp;
            if((counter > places) && (counter <= line.length()))
            {
                for(int h = places; h <= counter; h++)
                {
                    line[h] = 'x';
                    places++;
                }
            }
        }
    }
}

void out(string line)
{
    //Display output
    cout << "Output:\n" << line << endl;
}

/*Sample Run:
 * Enter a line of input:
Jare34 is a 65 mean 56th a
Output:
are34 is a xx mean 56th a
Do you want to rerun the program? Y for yes / N for no:
y
Enter a line of input:
I am 18
Output:
I am 18
Do you want to rerun the program? Y for yes / N for no:
y
Enter a line of input:
Bob34 is a 65 year old man
Output:
Bob34 is a xx year old man
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0
 */