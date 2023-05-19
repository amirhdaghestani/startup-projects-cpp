#include <iostream>

using namespace std;

int main()
{
    long int n = 0;
    cout << "Enter your number (your number must be between 1 and 10^9): ";
    cin >> n;
    if (n > 0 && n <= 1000000000)
    {
        switch (n)
        {
        case 1:
            cout << "One!" << endl;
            break;
        case 2:
            cout << "Two!" << endl;
            break;
        case 3:
            cout << "Three!" << endl;
            break;
        case 4:
            cout << "Four!" << endl;
            break;
        case 5:
            cout << "Five!" << endl;
            break;
        case 6:
            cout << "Six!" << endl;
            break;
        case 7:
            cout << "Seven!" << endl;
            break;
        case 8:
            cout << "Eight!" << endl;
            break;
        case 9:
            cout << "Nine!" << endl;
            break;
        
        default:
            cout << "Your number is greater than Nine!" << endl;
            break;
        }
    }
    else
        cout << "Your number must be between 1 and 10^9." << endl;
    return 0;
}