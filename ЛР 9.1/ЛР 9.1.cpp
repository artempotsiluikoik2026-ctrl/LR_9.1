//ЛР 9.1.cpp
//головний файл проєкту – функція main

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
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << "Arcth(x)" << endl;
    cout << setw(10) << "x"
         << setw(12) << "Arcth(x)"
         << setw(12) << "S"
         << setw(6) << "n" << endl;

    x = x_p;
    while (x <= x_k) {
        sum(); // виклик процедури обчислення суми

        cout << fixed << setprecision(5)
            << setw(10) << x
            << setw(12) << 0.5 * log((x + 1) / (x - 1))
            << setw(12) << s
            << setw(6) << n << endl; // форматний вивід

        x += dx;
    }

    cin.get();
    return 0;
}