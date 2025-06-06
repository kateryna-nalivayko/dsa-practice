#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<pair<long long, long long>> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].first >> P[i].second;
    }

    long long sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        int sign = ((n - 1 - i) % 2 == 0 ? +1 : -1);
        sx += sign * P[i].first;
        sy += sign * P[i].second;
    }

    if (n % 2 == 1) {
        cout << sx << " " << sy;
    } else {
        if (sx == 0 && sy == 0) {
            cout << 0;
        } else {
            cout << -1;
        }
    }

    return 0;
}
