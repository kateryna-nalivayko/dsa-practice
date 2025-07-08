#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long x = 1;

    while (true) {
        long long multiplied = x * N;
        long long moved = multiplied % 10;
        if (moved != N) {
            ++x;
            continue;
        }

        long long temp = multiplied / 10;
        long long shifted = N;
        long long factor = 10;

        while (temp > 0) {
            shifted *= 10;
            temp /= 10;
        }

        shifted += multiplied / 10;

        if (shifted == x * N) {
            cout << x << endl;
            break;
        }

        ++x;
    }

    return 0;
}
