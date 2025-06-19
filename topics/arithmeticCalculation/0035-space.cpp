/*Stepan is a great fan of spacecraft. He spends all his free time collecting, inventing, and constructing spacecraft. Stepan even had a 10-year contract for supplying spare parts with NASA, 
but after the Columbia shuttle disaster, there were no lengthy discussions, and the contract with Stepan was terminated. After this event, all the constructed spacecraft are stored at Stepan's home.
 A special source of pride in Stepan's collection of spacecraft is an example that consists of 2n parts. It was built by Stepan's grandfather, and the only thing known about the number 2n is the first 
 and last digit of its decimal representation. Help Serhii find n such that the number of parts 2n, from which the spacecraft could have been made, is minimal.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int r;
    if      (b == 2) r = 1;
    else if (b == 4) r = 2;
    else if (b == 8) r = 3;
    else if (b == 6) r = 0;
    else {
        cout << -1;
        return 0;
    }
    long long n0 = (r == 0 ? 4 : r);
    long double L = log10l(2.0L);
    long double low = log10l((long double)a);
    long double high = log10l((long double)(a + 1));
    long double step = fmodl(4.0L * L, 1.0L);
    long double f = fmodl(n0 * L, 1.0L);
    if (f < 0) f += 1.0L;
    for (long long n = n0; n <= 10000000; n += 4) {
        if (f >= low && f < high) {
            cout << n;
            return 0;
        }
        f += step;
        if (f >= 1.0L) f -= floorl(f);
    }
    cout << -1;
    return 0;
}
