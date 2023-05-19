#include <iostream>
using namespace std;

void update(int *a, int *b)
{
    int x = 0;
    x = *a;
    *a = *a + *b;
    if (x > *b)
        *b = x - *b;
    else
        *b = *b - x;
 
}
int main()
{
    int a,b;
    cout << "Enter your number in each line: " << endl;
    cin >> a;
    cin >> b;
    update(&a, &b);
    cout << endl << a << endl << b << endl;
    return 0;
}