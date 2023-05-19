#include <iostream>
using namespace std;

int main()
{
    int n = 0;;
    cout << "Enter the size of the array: (between 1 and 1000) " << endl;
    entry:
    cin >> n;
    if (n > 0 && n <= 1000)
    {
        entry2:
        int x[n];
        cout << "Enter the elemts of the array (divide them by a space, between 1 and 10000): " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            if (x[i] < 0 || x[i] > 10000)
            {
                cout << "Elements of array must be between 1 and 10000. try again!" << endl;
                goto entry2;
            }
        }
        for (int i = (n-1); i >= 0; i--)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Follow the rules! try again" << endl;
        goto entry;
    }
    
    return 0;
}