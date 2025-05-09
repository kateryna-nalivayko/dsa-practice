/*Three different integers are given, the modulus of each of which does not exceed 109.
Determine a number that is equal to one of the given numbers but is neither minimum nor
the maximum of them*/


#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    if ((a > b && a < c) || (a > c && a < b)) {
        cout << a;
    }
    else if ((b > a && b < c) || (b > c && b < a)) {
        cout << b;
    }
    else {
        cout << c;
    }

    return 0;
}
