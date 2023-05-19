#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Please enter your three number (Divide them by a space, numbers should be between 0 and 100): " << endl;
    cin >> a >> b >> c;
    if (0 <= a && 0 <= b && 0 <= c && a <= 1000 && b <= 1000 && c <= 1000)
        cout << "The sum of the three is: " << (a+b+c) << endl;
    else
        cout << "The numbers should be less than 1000 and greater than 0." << endl;
    return 0;
}