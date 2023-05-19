#include <iostream>
using namespace std;
int max_of_four(int a, int b, int c, int d)
{
    int max1, max2, max = 0;
    if (a > b)
        max1 = a;
    else
        max1 = b;

    if (c > d)
        max2 = c;
    else
        max2 = d;
    
    if (max1 > max2)
        max = max1;
    else
        max = max2;
    return max;
}
int main()
{
    int a,b,c,d;
    cout << "Enter your four number in each line: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << "The maximum is: " << max_of_four(a,b,c,d) << endl;
    return 0;
}