#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max1 = LLONG_MIN, max2 = LLONG_MIN;
    int cnt1 = 0;
    vector<ll> ans(n+1);

    for (int i = 0; i < n; i++) {
        ll x = a[i];
        if (x > max1) {
            max2 = max1;
            max1 = x;
            cnt1 = 1;
        }
        else if (x == max1) {
            cnt1++;
        }
        else if (x > max2) {
            max2 = x;
        }

        if (i >= 1) {  
            if (cnt1 >= 2) {
                ans[i+1] = max1;
            } else {
                ans[i+1] = max2;
            }
        }
    }

    for (int k = 2; k <= n; k++) {
        cout << ans[k] << (k < n ? ' ' : '\n');
    }

    return 0;
}
