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

int out(double hatSize, double hatSizeNew,double jacketSize, double jacketSizeNew, double waistSize, double waistSizeNew)
{
    cout << "Your hat size is " << hatSize << ", jacket size is " << jacketSize << " inches, and waist size is " << waistSize << " inches" << endl;
    cout << "In ten years, your hat size will be " << hatSizeNew << ", jacket size will be " << jacketSizeNew << " inches, and waist size will be " << waistSizeNew << " inches" << endl;
}

/*Sample Data:
 * Enter height in inches:-2
Enter height in inches:66
Enter weight in pounds:140
Enter age in years:18
Your hat size is 6.15, jacket si
ze is 37.78 inches, and waist size is 24.56 inches
In ten years, your hat size will be 6.15, jacket size will be 37.78 inches, and waist size will be 24.56 inches
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye

Process finished with exit code 0

 */