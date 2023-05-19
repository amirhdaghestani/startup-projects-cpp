#include <iostream>
using namespace std;

int main ()
{
    int a, b, i = 0;
    entery:
    cout << "Please enter your first positive number (non zero): ";
    cin >> a;
    cout << "Please enter you secound positive number (must be greater than the first number): ";
    cin >> b;
    if (b > a && a > 0)
    {
        for (i = a; i <= b; i++)
        {
            if ( i < 10)
            {
                switch (i)
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
                }
            }
            else
            {
                if (i%2 == 0)
                    cout << "Even!" << endl;
                else
                    cout << "Odd!" << endl;
            }
            
                
        }
    }
    else
    {
        cout << "You must follow the rules! try again!" << endl;
        goto entery;
    }
    
    return 0;
}