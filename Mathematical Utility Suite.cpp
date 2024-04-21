#include<iostream>
#include<math.h>
#include <cstdio>
using namespace std;

int Modular(int x, int y, int mod)
{
    int result = 1;

    x = x % mod;
    //y exponent         
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % mod;

        y = y / 2;
        x = (x * x) % mod;
    }
    return result;
}

int Gcd(int firstvalue, int secondvalue)
{

    if (secondvalue == 0)
    {

        cout << "A= " << firstvalue << " and B= " << secondvalue << endl;
        return firstvalue;
    }

    else
    {

        cout << "A= " << firstvalue << " and B= " << secondvalue << endl;
        return Gcd(secondvalue, firstvalue % secondvalue);
    }
}
int Bézout(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        cout << "x= " << a << " and y= " << b << endl;

        return a;
    }
    else {
        cout << "x= " << a << " and y= " << b << endl;
    }
    int x1, y1, gcd = Bézout(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
    int choice;
    int x = 1;
    int n1;
    int p;
    int n2;
    int x1, y1;
    int G;
    int a, b, s, t;
    int gcd;

    while (true) {
        cout << "__________________________________Main Menu_________________________________________" << endl;
        cout << "|                                                                                  |" << endl;
        cout << "|   1. Implement the Modular Exponentiation Algorithm .                            |" << endl;
        cout << "|   2. Find the least multiple common for two positive numbers.                    |" << endl;
        cout << "|   3. find Bézout coefficients (s) and (t) of a and b .                           |" << endl;
        cout << "|__________________________________________________________________________________|" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << endl;
            cout << "Enter the first value:";
            cin >> n1;

            cout << "Be careful! You should enter just positive integer number." << endl;
            cout << "Enter the second value: ";
            cin >> n2;
            if (n2 <= 0) {
                cout << "We apologize, but you did not commit to entering the correct numbers.";
                cout << endl;
                exit(1);
            }

            cout << "Be careful! You should enter 0 or any positive integer number." << endl;
            cout << "Enter the exponent: ";
            cin >> p;
            if (p < 0) {
                cout << "We apologize, but you did not commit to entering the correct numbers.";
                cout << endl;
                exit(1);

            }

            if (p != 0 && p > 0) {
                int a[15], i = 0;
                while (p != 0)
                {
                    a[i] = p % 2;
                    i++;
                    p = p / 2;
                }
                cout << "Equivalent Binary Value: ";
                for (i = (i - 1); i >= 0; i--) {
                    cout << a[i];
                }
                cout << endl;

                cout << "Enter the power again: ";
                cin >> p;
            }
            else {
                cout << "You should Enter positive integer: ";
                cin >> p;
            }
            cout << "The answer is: " << Modular(n1, p, n2) << endl;
            break;

        case 2:

            cout << endl;
            cout << "Enter two positive numbers " << endl;
            cout << "The first number: ";
            cin >> x1;
            cout << "The second number: ";
            cin >> y1;
            G = Gcd(x1, y1);

            cout << "GCD of:(" << x1 << " , " << y1 << ") is " << G << endl;;
            // lcm = (x*y)/gcd.
            cout << "LCM of:(" << x1 << " , " << y1 << ") is " << x1 * y1 / G;
            cout << endl;
            break;

        case 3:
            cout << endl;
            cout << "Enter the first value: ";
            cin >> a;
            cout << "Enter the second value: ";
            cin >> b;

            if (a < b) {
                swap(a, b);
            }
            gcd = Bézout(a, b, s, t);
            cout << "GCD: " << gcd << ",     S = " << s << ",     T = " << t << endl;
            break;

        default:
            cout << "Unkown Choice." << endl;
            exit(1);
        }

    }

    return 0;
}
