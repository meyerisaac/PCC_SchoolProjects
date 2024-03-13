#include <iostream>
using namespace std;
//Isaac Meyer & Samantha Santoro, CS002#71554

int main() {
    int x, y, product, total;

    cout << "Press return after entering a number.\n";
    cout << "Enter first number.\n";
    cin >> x;

    cout << "Enter second number;\n";
    cin >> y;

    product = x * y;
    total = x + y;

    cout << "If you have ";
    cout << x;
    cout << " and ";
    cout << y;
    cout << " then\n";
    cout << "the product is ";
    cout << product;
    cout << "\nand the sum is ";
    cout << total;

    cout << "\nThis is the end of the program, bye bye.";

    return 0;
}