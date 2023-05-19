#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
int main ()
{
    int a = 0;
    long int b = 0;
    char ch;
    float c = 0.0;
    double d = 0.0;

    // // Using cin and cout
    cin >> a >> b >> ch >> c >> d;
    cout << "Your Entery was: \n" << a << endl << b << endl << ch << endl;
    cout << fixed <<setprecision(3) << c << endl << setprecision(9) << d << endl;
    
    // Using scanf and printf
    // scanf("%d %ld %c %f %lf", &a, &b, &ch, &c, &d);
    // printf("%d %ld %c %.3f %.9lf \n", a, b, ch, c, d);
    
    return 0;
}