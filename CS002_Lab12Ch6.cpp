//File Name: Lab12Ch6.cpp
//Author: Isaac Meyer & James Donckels
//Email: imeyer@go.pasadena.edu & jdonckels1@go.pasadena.edu
//Assignment: Lab 12 Chapter 6 SVG Assignment
//Description: Write a function that allows the user to create a bar graph svg file
//Last Date Changed: 11/08/2022

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int CANVAS_HEIGHT = 500, CANVAS_WIDTH = 500;



void drawGraph(int height = CANVAS_HEIGHT, int width = CANVAS_WIDTH);
//Takes in either user inputted values for canvas height and width or default values to draw a graph
//I:Takes in input or default values
//O:No outputs, but programs a graph onto the .svg file

int main()
{
    char ans = 'y';

    ofstream outStream("BarGraph.svg");

    outStream.close();

    while(tolower(ans) == 'y')
    {

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void drawGraph(int height, int width)
{
    ofstream outStream("BarGraph.svg");

    outStream << R"(<?xml version="1.0" standalone="no"?>)";

    outStream.close();

}