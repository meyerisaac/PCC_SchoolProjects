//File Name: Assign12Ch7Prog3.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 12 Chapter 7 Program 3
//Description: This program will allow to create an array. Then the program will swap the first and last elements of the array
//Last Date Changed: 11/14/2022

#include <iostream>
using namespace std;

void fillArray(int a[], int size, int& numberUsed);
//Precondition: size is the declared size of the array a.
//Post-condition: numberUsed is the number of values stored in a.
//a[0] through a[numberUsed − 1] have been filled with

void swapFrontBack(int a[], int size);
//Precondition: size is the declared size of array a
//Post-condition: array a has its first and last elements swapped

void output(int a[], int size);
//Output the elements of the array in order

const int NUM_MAX = 10;

int main()
{
    char ans = 'y';

    //Prompt user to rerun the program
    while(tolower(ans) == 'y')
    {
        //Variable declarations
        int array[NUM_MAX], size = 0;

        //Input
        fillArray(array, NUM_MAX, size);

        //Processing
        swapFrontBack(array, size);

        //Output
        output(array, size);

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void fillArray(int a[], int size, int &numberUsed)
{
    using namespace std;
    cout << "Enter up to " << size << " negative whole numbers.\n"
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

void swapFrontBack(int a[], int size)
{
    int temp = a[0];
    a[0] = a[size - 1];
    a[size - 1] = temp;
}

void output(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

/*Sample Run:
 * Enter up to 10 negative whole numbers.
Mark the end of the list with a negative number.
2
Next Number:
6
Next Number:
4
Next Number:
1
Next Number:
-5
1
6
4
2
Do you want to rerun the program? Y for yes / N for no:
y
Enter up to 10 negative whole numbers.
Mark the end of the list with a negative number.
7
Next Number:

4
Next Number:
2
Next Number:
5
Next Number:
7
Next Number:
3
Next Number:
1
Next Number:
-6
1
4
2
5
7
3
7
Do you want to rerun the program? Y for yes / N for no:
n

 */