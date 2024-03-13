//FIle Name: Lab3Ch3.cpp
//Author: Isaac Meyer
//Email Address: imeyer@go.pasadena.edu
//Assignment: Lab 3 of Chapter 3 Coding Part
//Description: Simulate a simple game of blackjack and output if the user's optimal score or if they busted
//Last Edited: 09/13/2022

#include <iostream>
using namespace std;

int main()
{
    //Declare variables used
    char ans, loopAns;
    char card;
    int numCards, cardVal, totalVal;
    const int ACE_MAX = 11;
    const int ACE_MIN = 1;
    bool endProgram = false;
    bool haveAce = false;
    bool multiAce = true;

    //Repeat until we reach 5 cards, busted, or won
    do {
        numCards = 1;
        totalVal = 0;

        do {


            do {
                cardVal = 0;

                cout << "Enter card value(first letter if not a number):\n";
                cin >> card;

                switch (card)
                {
                    case 'A':
                    case 'a':
                        cardVal = ACE_MAX;
                        haveAce = true;
                        break;
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        cardVal = card - '0';
                        break;
                    case 'T':
                    case 't':
                    case 'J':
                    case 'j':
                    case 'Q':
                    case 'q':
                    case 'K':
                    case 'k':
                        cardVal = 10;
                        break;
                    default:
                        cout << "ERROR 001" << endl;
                }

                numCards++;
                totalVal += cardVal;

                if (totalVal == 21)
                {
                    cout << "You win and your score is: " << totalVal << endl;
                }

                if (totalVal > 21 && haveAce && multiAce)
                {
                    totalVal -= ACE_MAX;
                    totalVal += ACE_MIN;
                    multiAce = false;
                }

                if (totalVal > 21)
                {
                    cout << "Busted\n";
                    endProgram = true;
                }

                if (loopAns != 'Y' || loopAns != 'y')
                {
                    cout << "Score is: " << totalVal << endl;
                }

                if (!endProgram)
                cout << "Do you want to add another card?\n";
                cout << "Press Y for yes and N for no.\n";
                cin >> loopAns;

            } while (numCards <= 5 && (loopAns == 'Y' || loopAns == 'y') && endProgram);

        } while (numCards <= 5 && (loopAns == 'Y' || loopAns == 'y') && endProgram);

        cout << "Score is: " << totalVal << endl;

        cout << "Do you want to repeat the program?\n";
        cout << "Press Y for yes and N for no,\n";
        cout << "and then press return:";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "Good-Bye\n";
}
