//File Name: Lab5Ch4Menu.cpp
//Author: Isaac Meyer & James Donckels
//Email Address: imeyer@go.pasadena.edu & 1jdonckels@go.pasadena.edu
//Assignment: Lab 5 Chapter 4
//Description: We are trying to get a menu item from the user and validate it before giving an output
//Last Date Changed: 09/27/2022
#include <iostream>

const int NUMBER_OF_ITEMS = 4;

int Menu();
//This function based on given input between 1 and NUMBER_OF_ITEMS and returns the respective return value

int DisplayMenu();
//This function will display the items

int option1();
//Runs if option 1 is chosen

int option2();
//Runs if option 2 is chosen

int option3();
//Runs if option 3 is chosen

int main()
{
    using namespace std;

    //Declare variable for
    char ans;

    do
    {
        int optionNum = Menu();
        while(optionNum != 4)
        {
            switch(optionNum)
            {
                case 1:
                    option1();
                    break;
                case 2:
                    option2();
                    break;
                case 3:
                    option3();
                    break;
                default:
                    //Something went wrong
                    cout << "Invalid\n";
                    break;
            }
            optionNum = Menu();
        }

        //4 was selected to exit
        cout << "Exited Program\n";

        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";

    return 0;
}

int Menu()
{
    using namespace std;
    int option;

    option = DisplayMenu();
}

int DisplayMenu()
{
    using namespace std;
    int num;

    do
    {
        cout << "Choose an option 1-4:\n"
                "1, Item 1\n"
                "2, Item 2\n"
                "3, Item 3\n"
                "4, Exit\n";
        cin >> num;
    }while(num < 1 || num > NUMBER_OF_ITEMS);
    return num;
}

int option1()
{
    using namespace std;
    cout << "Item 1 has been selected\n";
    return 0;
}

int option2()
{
    using namespace std;
    cout << "Item 2 has been selected\n";
    return 0;
}

int option3()
{
    using namespace std;
    cout << "Item 3 has been selected\n";
    return 0;
}

/*
 * Choose an option 1-4:
1, Item 1
2, Item 2
3, Item 3
4, Exit
2
Item 2 has been selected
Choose an option 1-4:
1, Item 1
2, Item 2
3, Item 3
4, Exit
3
Item 3 has been selected
Choose an option 1-4:
1, Item 1
2, Item 2
3, Item 3
4, Exit
1
Item 1 has been selected
Choose an option 1-4:
1, Item 1
2, Item 2
3, Item 3
4, Exit
5
Choose an option 1-4:
1, Item 1
2, Item 2
3, Item 3
4, Exit
4
Exited Program
Do you want to repeat the program?
Press Y for yes and N for no,
and then press return:n
Good-Bye

Process finished with exit code 0

 */

