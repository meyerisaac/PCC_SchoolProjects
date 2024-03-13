//File Name: Assign11Ch6Proj11.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 11 Chapter 6 Project 11
//Description: Write a program that can take in 4 non-negative integer inputs and create an svg file
//of a bar graph scaled to the canvas size
//Last Date Changed:11/08/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int CANVAS_HEIGHT = 500, CANVAS_WIDTH = 500, NUM_BARS = 4, RGB = 255, HORIZONTAL_SHIT = 25, LINE_THICKNESS = 5;

void getNum(int& one, int& two, int& three, int& four, double& height, double& width);
//Takes in 4 call by reference integer variables and prompts the user to assign values to
//This validates input until all four variables have a valid input assigned to it

int getMax(int one, int two, int three, int four);
//Takes in 4 variables and returns the value of the max
//Input of the 4 variable values
//Outputs the largest variable value

double calculateScaleRate(int max, double height = CANVAS_HEIGHT);
//Calculates the scaling rate based on the maximum value and the height of the canvas
//Input of the max number and the height of canvas
//Outputs a scaled rate between the number of integer and the height of the canvas

void scaleNumbers(double scaleRate, int one, int two, int three, int four, double& first, double& second, double& third, double& fourth);
//Converts all the integers into their scaled doubles

double calculateBarWidth(int numBars, double width = CANVAS_WIDTH);
//Calculate the width of the bars
//Input of the number of bars and the width of the canvas
//Outputs the width of each bar

void writeHeader(ofstream& fout, double height = CANVAS_HEIGHT, double width = CANVAS_WIDTH);
//Write the appropriate headers for the svg file given the canvas size

void drawLines(ofstream& fout, double height = CANVAS_HEIGHT, double width = CANVAS_WIDTH);
//Draws the lines for the bar graph
//Input of the canvas height and width
//Writes the code for the lines onto the svg file

void drawBars(ofstream& fout, double num, double barWidth, int max, int number);
//Draw each of the bars in their appropriate coordinates
//Input of the scaled height of each bars along with the barWidth
//Outputs the bars with random colors as well

void writeFooter(ofstream& fout);
//Write the footer and end of the svg file

void drawBarGraph();
//The main function that orders and has all the organized functions within it

int main()
{
    char ans = 'y';

    //Repeat if user wants
    while(tolower(ans) == 'y')
    {
        //Draw a graph
        drawBarGraph();

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void getNum(int& one, int& two, int& three, int& four, double& height, double& width)
{
    //Prompt user for input
    cout << "Enter 4 numbers for the height of each of the bars:\n";
    cin >> one >> two >> three >> four;

    char ans;

    //Ask if user wants a custom canvas size
    cout << "Do you want to enter your own canvas height and width? Y for yes N for no\n";
    cin >> ans;

    if(tolower(ans) == 'y')
    {
        height = 0, width = 0;
        while(height <= 0 || width <= 0)
        {
            cout << "Enter a positive height:\n";
            cin >> height;
            cout << "Enter a positive width:\n";
            cin >> width;
        }
    }
    else
    {
        height = CANVAS_HEIGHT;
        width = CANVAS_WIDTH;
    }
}

int getMax(int one, int two, int three, int four)
{
    //Sort out the largest number
    int temp = one;
    if(two > temp)
    {
        temp = two;
    }
    if(three > temp)
    {
        temp = three;
    }
    if(four > temp)
    {
        temp = four;
    }
    return temp;
}

double calculateScaleRate(int max, double height)
{
    return (height / max);
}

void scaleNumbers(double scaleRate, int one, int two, int three, int four, double& first, double& second, double& third, double& fourth)
{
    first = one * scaleRate;
    second = two * scaleRate;
    third = three * scaleRate;
    fourth = four * scaleRate;
}

double calculateBarWidth(int numBars, double width)
{
    return width / (numBars * 1.5);
}

void writeHeader(ofstream& fout, double height, double width)
{
    string svgFileHeader = "<?xml version=\"1.0\" standalone=\"no\"?>\n"
                           "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    string canvasSize = "<svg width=\""
                        + to_string(width)
                        + "\" height=\"" + to_string(height)
                        + "\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    fout << svgFileHeader << canvasSize;
}

void drawLines(ofstream& fout, double height, double width)
{
    string graphLines = "<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"" + to_string(height)
                        + "\" style=\"stroke:black;stroke-width:5\"/>\n"
                        + "<line x1=\"0\" y1=\"" + to_string(height) + "\" x2=\"" + to_string(width)
                        + "\" y2=\"" + to_string(height) + "\" style=\"stroke:black;stroke-width:5\"/>\n";

    fout << graphLines;
}

void drawBars(ofstream& fout, double num, double barWidth, int max, int number)
{
    double barGap = barWidth / 2;
    int red = rand() % RGB, green = rand() % RGB, blue = rand() % RGB;

    string bar = "<rect x=\"" + to_string(((barWidth + barGap) * number) + HORIZONTAL_SHIT)
                 + "\" y=\"" + to_string(CANVAS_HEIGHT - num)
                 + "\" width=\"" + to_string(barWidth)
                 + "\" height=\"" + to_string(num - LINE_THICKNESS)
                 + "\" style=\"fill:rgb(" + to_string(red)
                 + "," + to_string(blue)
                 + "," + to_string(green) + ");\"/>\n";

    fout << bar;
}

void drawBarGraph()
{
    srand(time(0));
    ofstream out("BarGraphProj11.svg");
    if(out.fail())
    {
        cout << "Error Opening File To Write\n";
        exit(1);
    }

    int inOne, inTwo, inThree, inFour, max, numBars = NUM_BARS;
    double outOne, outTwo, outThree, outFour, height, width, scaleRate;

    getNum(inOne, inTwo, inThree, inFour, height, width);
    max = getMax(inOne, inTwo, inThree, inFour);
    scaleRate = calculateScaleRate(max, height);
    scaleNumbers(scaleRate, inOne, inTwo, inThree, inFour, outOne, outTwo, outThree, outFour);

    //Write onto the file
    writeHeader(out, height, width);
    drawLines(out, height, width);
    drawBars(out, outOne, calculateBarWidth(numBars, width), max, 0);
    drawBars(out, outTwo, calculateBarWidth(numBars, width), max, 1);
    drawBars(out, outThree, calculateBarWidth(numBars, width), max, 2);
    drawBars(out, outFour, calculateBarWidth(numBars, width), max, 3);
    writeFooter(out);

    out.close();
}

void writeFooter(ofstream& fout)
{
    fout << "</svg>";
}

/*Sample Run:
 * Enter 4 numbers for the height of each of the bars:
100 200 300 400
Do you want to enter your own canvas height and width? Y for yes N for no
n
Do you want to rerun the program? Y for yes / N for no:
n
 */
//Should have a graph of 4 bars in ascending order with different colors