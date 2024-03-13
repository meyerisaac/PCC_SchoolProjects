//File Name: Assign15Ch8Proj2.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 15 Chapter 8 Project 2
//Description: This program will take in any line of text and tell you the number of words along with
//how many times each letter occurs within that text
//Last Date Changed: 12/05/2022

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_INPUT_LENGTH = 80, NUM_LETTERS = 26;

void getInput(char line[]);
//Precondition: An empty C_string
//Post-condition: A filled in C_string

int countWords(char line[]);
//Takes in a C_string and returns the number of words
//I: Takes in a C_string
//O: Outputs the number of words in the string

int whatAlpha(char letter);
//Computes the number conversion of the given character
//I: Takes in a character
//O: Returns a corresponding integer

char alphaNum(int num);
//Computes the character conversion of the given integer
//I: Takes in an integer
//O: Returns a corresponding character

void countLetters(char line[], int count[]);
//Precondition: C_string and an empty count[] array
//Post-condition: count[] array filled in with the correct occurrences of each respective letter

void out(int count[], int numWords);
//Precondition: Takes in the count[] array and the number of words
//Post-condition: Displays everything in our desired formats

int main()
{
    //Declare repeat character
    char ans = 'y';

    //Loop until user wants to
    while(tolower(ans) == 'y')
    {
        //Declare arrays
        char line[MAX_INPUT_LENGTH];
        int count[NUM_LETTERS] = {};
        int numWords;

        //Input
        getInput(line);

        //Processing
        numWords = countWords(line);
        countLetters(line, count);

        //Output
        out(count, numWords);

        //Prompt user for a repeat of the program
        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
        cin.ignore();
    }
    return 0;
}

void getInput(char line[])
{
    //Prompt user for input
    cout << "Enter a line of text:\n";

    //Take in line of input
    cin.getline(line, MAX_INPUT_LENGTH);
}

int countWords(char line[])
{
    //Declare variables
    char space = ' ', period = '.', comma = ',';
    int place = 1, count = 1;

    //Loop until end of array
    while(place < strlen(line))
    {
        if(line[place] == space || line[place] == period || line[place] == comma)
        {
            //Increase counter for each space
            count++;
        }
        place++;
    }

    return count;
}

int whatAlpha(char letter)
{
    switch(tolower(letter))
    {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
        default:
            cout << "Error in whatAlpha()\n";
            break;
    }
}

char alphaNum(int num)
{
    switch(num)
    {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        case 7:
            return 'h';
        case 8:
            return 'i';
        case 9:
            return 'j';
        case 10:
            return 'k';
        case 11:
            return 'l';
        case 12:
            return 'm';
        case 13:
            return 'n';
        case 14:
            return 'o';
        case 15:
            return 'p';
        case 16:
            return 'q';
        case 17:
            return 'r';
        case 18:
            return 's';
        case 19:
            return 't';
        case 20:
            return 'u';
        case 21:
            return 'v';
        case 22:
            return 'w';
        case 23:
            return 'x';
        case 24:
            return 'y';
        case 25:
            return 'z';
        default:
            cout << "Error with alphaNum()\n";
            break;
    }
}

void countLetters(char line[], int count[])
{
    //Declare variables
    int place = 0, temp;

    //Loop until end of array
    while(place < strlen(line))
    {
        if(isalpha(line[place]))
        {
            temp = whatAlpha(line[place]);
            count[temp]++;
        }
        place++;
    }
}

void out(int count[], int numWords)
{
    char space = ' ';

    //Output the number of words
    cout << numWords << space << "word(s)" << endl;

    //Only output the number of each letter than appears more than 0 times
    for(int i = 0; i < NUM_LETTERS; i++)
    {
        if(count[i] > 0)
        {
            cout << count[i] << space << alphaNum(i) << endl;
        }
    }
}

/*Sample Run:
 * Enter a line of text:
Hello
1 word(s)
1 e
1 h
2 l
1 o
Do you want to rerun the program? Y for yes / N for no:
y
Enter a line of text:
Hi James
2 word(s)
1 a
1 e
1 h
1 i
1 j
1 m
1 s
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0
 */