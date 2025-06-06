#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += a[i];
    }

    long long prefix = 0;
    for (int i = 1; i <= n; i++) {
        prefix += a[i];
        long long leftSum = prefix - a[i];
        long long rightSum = total - prefix;
        if (leftSum == rightSum && i > 1 && i < n) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
    return 0;
}
