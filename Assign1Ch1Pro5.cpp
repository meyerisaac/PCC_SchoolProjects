#include <iostream>
using namespace std;
//Isaac Meyer Assignment 1 Chapter 1 CS002#71554

int main()
{
    int width, length, total_length;

    cout << "Press return after entering a number.\n";
    cout << "Enter the width.\n";

    cin >> width;

    cout << "Enter the length;\n";
    cin >> length;
    total_length = 2 * width + 2 * length;
    cout << "If the width is ";
    cout << width;
    cout << " and";
    cout << " the length is ";
    cout << length;
    cout << "\nyou will have ";
    cout << total_length;
    cout << " total length of fence to fence.\n";

    return 0;
}

//I have the user enter a length that is stored in variable 'length'
//and width that is stored in variable 'width'
//then the program will multiply each variable by 2 before adding them together
//the total is placed into variable 'total_length' which is then outputted to the user
