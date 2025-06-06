#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll b = max({0LL, -x, y});
        ll a = x + b;
        ll c = b - y;
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
