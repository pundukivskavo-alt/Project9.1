//////////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
//                  головний файл проекту – функція main

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    const double PI_2 = 1.57079632679489661923;   // pi/2

    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << "arccos(x) via Taylor series" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "|" << setw(8) << "x"
        << "|" << setw(14) << "acos(x)"
        << "|" << setw(14) << "pi/2-sum"
        << "|" << setw(6) << "n" << "|" << endl;
    cout << "-----------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        sum();                  // виклик процедури обчислення суми

        cout << "|" << fixed << setw(8) << setprecision(3) << x
            << "|" << setw(14) << setprecision(8) << acos(x)
            << "|" << setw(14) << PI_2 - s
            << "|" << setw(6) << n << "|" << endl;

        x += dx;
    }
    cout << "-----------------------------------------------" << endl;

    cin.get(); cin.get();
    return 0;
}