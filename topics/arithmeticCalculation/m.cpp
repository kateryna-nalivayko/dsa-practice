#include <iostream>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();
    int max3 = numeric_limits<int>::min();
    int min1 = numeric_limits<int>::max();
    int min2 = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        // Update max values
        if (x > max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max3 = max2;
            max2 = x;
        } else if (x > max3) {
            max3 = x;
        }

        // Update min values
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    long long prod1 = 1LL * max1 * max2 * max3;
    long long prod2 = 1LL * min1 * min2 * max1;

    if (prod1 >= prod2) {
        cout << max1 << " " << max2 << " " << max3 << "\n";
    } else {
        cout << min1 << " " << min2 << " " << max1 << "\n";
    }

    return 0;
}
