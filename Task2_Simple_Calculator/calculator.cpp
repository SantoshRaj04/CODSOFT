#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;
    int choice;

    cout << "=====================================\n";
    cout << "        SIMPLE CALCULATOR\n";
    cout << "=====================================\n";

    // Taking input from user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Displaying menu
    cout << "\nChoose an operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";

    cout << "\nEnter your choice (1-4): ";
    cin >> choice;

    // Performing selected operation
    switch (choice)
    {
        case 1:
            result = num1 + num2;
            cout << "\nResult = " << result;
            break;

        case 2:
            result = num1 - num2;
            cout << "\nResult = " << result;
            break;

        case 3:
            result = num1 * num2;
            cout << "\nResult = " << result;
            break;

        case 4:
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "\nResult = " << result;
            }
            else
            {
                cout << "\nError! Division by zero is not allowed.";
            }
            break;

        default:
            cout << "\nInvalid choice! Please select between 1 and 4.";
    }

    cout << "\n\nThank you for using the calculator!\n";

    return 0;
}