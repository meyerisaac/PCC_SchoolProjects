//File Name:Assign5Ch4Proj3.cpp
//Author:Isaac Meyer
//Email Address:imeyer@go.pasadena.edu
//Assignment:Assignment 5 Chapter 4 Project 3
//Description:Take in 3 inputs and calculate the 3 different variables
//Last Date Changed:09/29/2022

#include <iostream>
#include <cmath>
using namespace std;

double hatSize(int height, double weight);
//This program will give hat size in inches with the given inputs

double jacketSize(int height, double weight, int age);
//This program will give jacket size in inches with the given inputs

double waistSize(double weight, int age);
//This program will give the waist size in inches with given inputs

double futureJacketWaistSize(int age, int height, double weight, int years);
//This is just an additional function that we wills set default values of years = 10 to

int out(double hatSize, double hatSizeNew, double jacketSize, double jacketSizeNew, double waistSize, double waistSizeNew);
//This program will be our output function giving us the 3 calculations now and in 10 years

//Declare all needed global variables
const int MIN_HEIGHT = 1, MAX_HEIGHT = 108, MIN_WEIGHT = 1, MAX_WEIGHT = 1400, MIN_AGE = 1, MAX_AGE = 125, TEN_YEARS = 10;

int main()
{
    //Declare variables used in the main program
    char ans;
    int height, age;
    double weight;
    int placeholder;

    //Set the precision point
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    //Repeat and validate the inputs
    do
    {
        do
        {
            cout << "Enter height in inches:";
            cin >> height;
            height = floor(height);
        }while(height < MIN_HEIGHT || height > MAX_HEIGHT);
        do
        {
            cout << "Enter weight in pounds:";
            cin >> weight;
        }while(weight < MIN_WEIGHT || weight > MAX_WEIGHT);
        do
        {
            cout << "Enter age in years:";
            cin >> age;
        }while(age < MIN_AGE || age > MAX_AGE);

        //We use placeholder variable with no value to simulate what the function would do with no inputted value and resorting to the default value
        futureJacketWaistSize(age, height, weight, placeholder);

        //Output the different calculated sizes and measurements
        out(hatSize(height, weight), hatSize(height, weight), jacketSize(height, weight, age), jacketSize(height, weight, age + TEN_YEARS),
            waistSize(weight, age), waistSize(weight, age + TEN_YEARS));

        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(tolower(ans) == 'y');

    cout << "Good-Bye\n";

    return 0;
}

double hatSize(int height, double weight)
{
    const double HAT_SIZE_MULTI = 2.9;

    double out = (weight / height) * HAT_SIZE_MULTI;

    return out;
}

double jacketSize(int height, double weight, int age)
{
    const int THIRTY_YEARS = 30, JACKET_SIZE_DIV = 288;
    const double ONE_EIGHTH = 0.125;
    double addSize;

    if(age > THIRTY_YEARS)
    {
        addSize = (age - THIRTY_YEARS) * ONE_EIGHTH;
    }
    double out = ((height * weight) / JACKET_SIZE_DIV) + addSize;

    return out;
}

double waistSize(double weight, int age)
{
    const double WEIGHT_SIZE_MULTI = 5.7, TENTH = 0.1;
    const int YEARS = 2, THRESH = 28;
    double addSize, out;

    if(age >= (THRESH + YEARS))
    {
        addSize = (age - THRESH) * TENTH;
        out = (weight / WEIGHT_SIZE_MULTI) + addSize;
        return out;
    }
    out = (weight / WEIGHT_SIZE_MULTI);

    return out;
}

double futureJacketWaistSize(int age, int height, double weight, int years = TEN_YEARS)
{
    int jackSize = jacketSize(height, weight, age + years);
    int waiSize = waistSize(weight, age + years);
    cout << "Using the futureJacketWaistSize function, we see that in ten years, jacket size will be " << jackSize << " inches and waist size will be " << waiSize << " inches.\n";
}

int out(double hatSize, double hatSizeNew,double jacketSize, double jacketSizeNew, double waistSize, double waistSizeNew)
{
    cout << "Your hat size is " << hatSize << ", jacket size is " << jacketSize << " inches, and waist size is " << waistSize << " inches" << endl;
    cout << "In ten years, your hat size will be " << hatSizeNew << ", jacket size will be " << jacketSizeNew << " inches, and waist size will be " << waistSizeNew << " inches" << endl;
}

/*Sample Data:
 * Enter height in inches:14
Enter weight in pounds:234
Enter age in years:23
Using the futureJacketWaistSize function, we see that i
n ten years, jacket size will be 11 inches and waist size will be 41 inches.
Your hat size is 48.47, jacket size is 11.75 inches, and waist size is 41.05 inches
In ten years, your hat size will be 48.47, jacket size will be 11.75 inches, and waist size will be 41.55 inches
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:y
Enter height in inches:60
Enter weight in pounds:150
Enter age in years:20
Using the futureJacketWaistSize f
unction, we see that in ten years, jacket size will be 31 inches and waist size will be 26 inches.
Your hat size is 7.25, jacket size is 36.95 inches, and waist size is 26.32 inches
In ten years, your hat size will be 7.25, jacket size will be 36.95 inches, and waist size will be 26.52 inches
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye

Process finished with exit code 0

 */