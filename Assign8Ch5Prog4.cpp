//File Name: Assign8Ch5Prog4.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 8 Chapter 5 Program 4
//Description: This program will ask the user if they want to convert from meters to feet or vice versa. Then the program will ask the user
//for the values to be converted and perform those calculations. Finally, the program will output the converted answers
//Last Date Changed: 10/17/2022

#include <iostream>
using namespace std;

int menu();
//Function will retrieve what kind of conversions the user wants to do
//I:No inputs
//O:Outputs int 1 or 2

void getInput(double& first, double& second, int ans);
//Prompt user for the inputs based on their option chosen
//I:Variables we'll be giving the value to
//O:N/A

bool inputVal(double& first, double& second);
//Prompt user for inputs until we get a valid input
//I:Call by reference variables that we'll be using
//O:True when input is valid and false when not

void metricToStandard(double& m, double& cm, double& ft, double& in, int ans);
//Get metric inputs and converts them to standard
//I:Variables containing the value we'll alter
//O:N/A

void standardToMetric(double& ft, double& in, double& m, double& cm, int ans);
//Get standard units and converts to metric
//I:Variables we'll be altering
//O:N/A

void cmConvert(double cm, double& m);
//Takes in the cm, applies conversion, and assign the value to m

void inConvert(double in, double& ft);
//Takes in the inches, applies conversion, and assigns the value to ft

void mConvert(double m, double& cm);
//Takes in meters, applies conversion, and assigns the value to cm

void ftConvert(double ft, double& in);
//Takes in ft, applies conversion, and assigns value to inches

void out(double& first, double& second, int option);
//The output function
//I:Takes in the values that we converted to and option num, so we know what the resulting format should be
//O:N/A

//Declare constants
const double HUNDRED = 100, TWELVE = 12, FEET_METERS = 0.3048, METERS_FEET = 3.2801;
const int ZERO = 0, OPTION_ONE = 1, OPTION_TWO = 2;

int main()
{
    //Set precision point to 4
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    //Declare variables
    char userAns = 'y';

    //Allow user to repeat program
    while(tolower(userAns) == 'y')
    {
        //Declare variables
        double meters, cm, feet, in;

        //Assign the result of menu() to answer, so we can continue to use it later
        int ans = menu();

        switch(ans)
        {
            case OPTION_ONE:
                metricToStandard(meters, cm, feet, in, OPTION_ONE);
                break;
            case OPTION_TWO:
                standardToMetric(feet, in, meters, cm, OPTION_TWO);
                break;
            default:
                cout << "Error001:Error with main() switch function\n";
                break;
        }

        //Prompt user if they want to rerun the program
        cout << "Do you want to rerun the program? Y for Yes / N for No\n";
        cin >> userAns;
    }

    return 0;
}

int menu()
{
    //Declare temp var
    int ans = ZERO;

    //Prompt user for their choice until valid input
    while(ans < OPTION_ONE || ans > OPTION_TWO)
    {
        cout << "Do you want to convert from:\n"
             << "1 - Metric To Standard\n"
             << "2 - Standard To Metric\n";
        cin >> ans;
    }

    //Return the answer
    return ans;
}

void getInput(double& first, double& second, int ans)
{
    //Run through a switch statement to get the correct prompt until we get valid input
    switch(ans)
    {
        case OPTION_ONE:

            cout << "What are your meter(s) and centimeter(s) in 3 20 format:\n";
            cin >> first >> second;

            while(!inputVal(first, second))
            {
                cout << "Error: What are your meter(s) and centimeter(s) in 3 20 format:\n";
                cin >> first >> second;
            }

            break;
        case OPTION_TWO:

            cout << "What are your feet and inch(es) in 5 8 format:\n";
            cin >> first >> second;

            while(!inputVal(first, second))
            {
                cout << "Error: What are your feet and inch(es) in 5 8 format:\n";
                cin >> first >> second;
            }

            break;
        default:
            cout << "Error002:Problem With getInput()\n";
            break;
    }
}

bool inputVal(double& first, double& second)
{
    //Check to make sure input isn't negative
    if(first < ZERO || second < ZERO)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void metricToStandard(double& m, double& cm, double& ft, double& in, int ans)
{
    //Get input
    getInput(m, cm, ans);

    //Perform te conversion and calculations
    cmConvert(cm, m);
    ft = m * METERS_FEET;

    int temp = ft;

    ftConvert((ft - temp), in);
    ft = temp;

    //Display output
    out(ft, in, ans);
}

void standardToMetric(double& ft, double& in, double& m, double& cm, int ans)
{
    //Get input
    getInput(ft, in, ans);

    //Perform calculations
    inConvert(in, ft);
    m = ft * FEET_METERS;

    int temp = m;

    mConvert((m - temp), cm);
    m = temp;

    //Display output
    out(m, cm, ans);
}

void cmConvert(double cm, double& m)
{
    m += cm / HUNDRED;
}

void inConvert(double in, double& ft)
{
    ft += in / TWELVE;
}

void mConvert(double m, double& cm)
{
    cm = m * HUNDRED;
}

void ftConvert(double ft, double& in)
{
    in = ft * TWELVE;
}

void out(double& first, double& second, int option)
{
    //Set precision to 2 for output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Display in format of correct option
    switch(option)
    {
        case OPTION_ONE:
            cout << "You now have " << first << " ft and " << second << " inch(es)\n";
            break;
        case OPTION_TWO:
            cout << "You now have " << first << " meter(s) and " << second << " centimeter(s)\n";
            break;
        default:
            cout << "Error004:Output Error\n";
            break;
    }
}

/*Sample Run:
 * Do you want to convert from:
1 - Metric To Standard
2 - Standard To Metric
1
What are your meter(s) and centimeter(s) in 3 20 format:
0.5 0
You now have 1.0000 ft and 7.6806 inch(es)
Do you want to rerun the program? Y for Yes / N for No
y
Do you want to convert from:
1 - Metric To Standard
2 - Standard To Metric
1
What are your meter(s) and centimeter(s) in 3 20 format:
0 200
You now have 6.0000 ft and 6.7224 inch(es)
Do you want to rerun the program? Y for Yes / N for No
y
Do you want to convert from:
1 - Metric To Standard
2 - Standard To Metric
2
What are your feet and inch(es) in 5 8 format:
0 18
You now have 0.0000 meter(s) and 45.7200 centimeter(s)
Do you want to rerun the program? Y for Yes / N for No
n

Process finished with exit code 0
 */