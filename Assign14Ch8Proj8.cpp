//File Name: Assign14Ch8Proj8.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 14 Chapter 8 Project 8
//Description: This program will sort all the integers in a vector from least to greatest
//Last Date Changed: 12/01/2022

#include <iostream>
#include <vector>
using namespace std;

void fillVector(vector<int>& numbers);
//Gets a vector input from the user
//I:Takes in a call by reference vector
//O:No Outputs, will return the vector with filled in

void sort(vector<int>& nums);
//Sorts the vector from least to greatest
//I:Takes in a call by reference vector
//O:No Outputs, will return the sorted vector

int indexOfSmallest(vector<int>& nums, int startIndex);
//Checks for the current smallest integer in vector
//I:Takes in a call by reference vector and the starting index of the search
//O:Outputs the index of the smallest element

void out(vector<int> nums);
//Outputs the vector in desired format
//I:Takes in a vector
//O:No Outputs, will display the vector in desired format

int main()
{
    char ans = 'y';

    while(tolower(ans) == 'y')
    {
        //Declare vector
        vector<int> nums;

        //Input
        fillVector(nums);

        //Processing
        sort(nums);

        //Output
        out(nums);

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void fillVector(vector<int>& numbers)
{
    //Declare temp variable
    int next;

    //Prompt user for input
    cout << "Enter numbers seperated by a space(mark the end of list with a negative number):\n";

    //Put all the keyboard input integers into a vector by pushing them back
    while(cin >> next && next >= 0)
    {
        numbers.push_back(next);
    }
}

void sort(vector<int>& nums)
{
    //Declare the variable we're using for the smallest element
    int indexOfNextSmallest;
    for (int index = 0; index < nums.size(); index++)
    {
        //Place the correct value in a[index]:
        indexOfNextSmallest = indexOfSmallest(nums, index);
        int temp;
        temp = nums[index];
        nums[index] = nums[indexOfNextSmallest];
        nums[indexOfNextSmallest] = temp;
        //a[0] <= a[1] <=...<= a[index] are the smallest of the original array
        //elements. The rest of the elements are in the remaining positions.
    }
}

int indexOfSmallest(vector<int>& nums, int startIndex)
{
    int min = nums[startIndex],
    indexOfMin = startIndex;
    for (int index = startIndex + 1; index < nums.size(); index++)
    {
        if (nums[index] < min)
        {
            min = nums[index];
            indexOfMin = index;
            //min is the smallest of a[startIndex] through a[index]
        }
    }

return indexOfMin;
}

void out(vector<int> nums)
{
    //Format
    cout << "The new order is as follows:";

    //Loop until all the elements are outputted
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

/*Sample Run:
 * Enter numbers seperated by a space(mark the end of list with a negative number):
7 6 1 8 3 2 -1
The new order is as follows:1 2 3 6 7 8
Do you want to rerun the program? Y for yes / N for no:
y
Enter numbers seperated by a space(mark the end of list with a negative number):
7 6 2 10 293 28 93 75
-1
The new order is as follows:2 6 7 10 28 75 93 293
Do you want to rerun the program? Y for yes / N for no:
n

Process finished with exit code 0
 */