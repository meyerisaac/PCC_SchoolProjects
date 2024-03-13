//File Name: Assign11Ch6Proj12.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 11 Chapter 6 Project 12
//Description:
//Last Date Changed: 11/08/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void startProgram();

void writeHeader(ofstream& fout);
//Write the header of the svg file

void drawFace();

void writeFooter(ofstream& fout);
//Write the footer of the svg file

int main()
{
    char ans = 'y';

    while(tolower(ans) == 'y')
    {
        startProgram();

        drawFace();

        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

void startProgram()
{
    char ans;

    cout << "Are you ready to see the picture? Y for yes / N for no\n";
    cin >> ans;

    if(tolower(ans) != 'y')
    {
        cout << "Okay. Bye then. :(\n";
        exit(1);
    }
    else
    {
        cout << "Here we goo!\n";
    }
}

void writeHeader(ofstream& fout)
{
    fout << "<?xml version=\"1.0\" standalone=\"no\"?>\n"
            "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
            "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">\n";
}

void drawFace()
{
    ofstream out("portrait.svg");
    if(out.fail())
    {
        cout << "Stream Open Fail\n";
        exit(1);
    }

    writeHeader(out);

    //Draw the ellipse for the head
    out << "<ellipse cx=\"250\" cy=\"250\" rx=\"100\" ry=\"110\" style=\"fill:rgb(248, 190, 172);stroke:grey;stroke-width:1\"/>\n";

    //Draw 2 gradiant ellipses for the eyes
    out << "<ellipse cx=\"200\" cy=\"220\" rx=\"30\" ry=\"25\" style=\"fill:grey;stroke:grey;stroke-width:1\"/>\n";
    out << "<ellipse cx=\"300\" cy=\"220\" rx=\"30\" ry=\"25\" style=\"fill:grey;stroke:grey;stroke-width:1\"/>\n";

    //Draw the nose
    out << "<polyline points=\"250,250 220,280 280,280\"\n" "  style=\"fill:none;stroke:black;stroke-width:3\" />\n";

    //Draw the mouth
    out << "<line x1=\"200\" y1=\"320\" x2=\"300\" y2=\"320\" style=\"stroke:black;stroke-width:5\" />\n";

    writeFooter(out);

    out.close();

    cout << "Face Drawn!\n";
}

void writeFooter(ofstream& fout)
{
    fout << "</svg>\n";
}