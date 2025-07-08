#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // If there are exactly three numbers, output them directly
    if (N == 3) {
        cout << a[0] << " " << a[1] << " " << a[2] << "\n";
        return 0;
    }

    // Track the three largest and two smallest values
    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (auto x : a) {
        // Update top three maxima
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
        // Update two minima
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    // Compute products
    long long prod1 = max1 * max2 * max3;
    long long prod2 = max1 * min1 * min2;

    // Choose the triplet with the maximum product
    if (prod1 >= prod2) {
        cout << max1 << " " << max2 << " " << max3 << "\n";
    } else {
        cout << max1 << " " << min1 << " " << min2 << "\n";
    }

    return 0;
}
