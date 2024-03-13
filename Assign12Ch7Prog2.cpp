//File Name: Assign12Ch7Prog2
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 12 Chapter 7 Program 2
//Description: This program will let the user create an array up the maximum constant size and fill it up with
//numbers of their choice. Then the program will run and find the number of 2s that are in each array.
//Last Date Changed: 11/14/2022

#include <iostream>
#include <string>
using namespace std;

void fillArray(int a[], int size, int& numberUsed);
//Precondition: size is the declared size of the array a.
//Post-condition: numberUsed is the number of values stored in a.
//a[0] through a[numberUsed − 1] have been filled with

void countTwos(int a[], int size, int& out);
//Precondition: size is the declared size of array a
//Post-condition: out is the number of 2s found in the array
//Ran a loop through the elements of the array to count the number of 2s

void output(int out);
//Runs an output statement telling the user how manny 2s were found

const int MAX_NUM = 10, NUM_COMPARE = 2;

int main()
{
    char ans = 'y';

    //Prompt user to rerun the program
    while(tolower(ans) == 'y')
    {
        //Variable Declarations
        int a[MAX_NUM], numElements = 0, out = 0;

        //Input
        fillArray(a, MAX_NUM, numElements);

        //Processing
        countTwos(a, numElements, out);

        //Output
        output(out);

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void fillArray(int a[], int size, int &numberUsed)
{
    using namespace std;
    cout << "Enter up to " << size << " non-negative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        cout << "Next Number:\n";
        a[index] = next;
        index++;
        cin >> next;
    }
    numberUsed = index;
}

void countTwos(int a[], int size, int& out)
{
    out = 0;

    for(int i = 0; i < size; i++)
    {
        if(a[i] == NUM_COMPARE)
        {
            out++;
        }
    }
}

void output(int out)
{
    cout << "The number of 2s are " << out << endl;
}

/*Sample Run:
 * Enter up to 10 non-negative whole numbers.
Mark the end of the list with a negative number.
2
Next Number:
4
Next Number:
3
Next Number:
2
Next Number:
6
Next Number:
8
Next Number:
5
Next Number:
2
Next Number:
5
Next Number:
-5
The number of 2s are 3
Do you want to rerun the program? Y for yes / N for no:
y
Enter up to 10 non-negative whole numbers.
Mark the end of the list with a negative number.
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
Next Number:
2
The number of 2s are 10
Do you want to rerun the program? Y for yes / N for no:
2

Process finished with exit code 0
 */