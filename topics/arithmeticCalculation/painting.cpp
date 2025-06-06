#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long S = n + 2*m;
    long long r = S / 2;

    long long ans = 0;
    if (r < 2) {
        ans = 0;
    }
    else if (n <= 1) {
        long long r2 = r / 2;
        if (r2 < 2) {
            ans = 0;
        } else {
            long long u = r2 / 2;
            long long v = r2 - u;
            ans = 4 * u * v;
        }
    }
    else if (n <= 3) {
        long long a = r / 2;
        long long b = r - a;
        if ((r % 2 == 0) && ((a % 2) == 1) && ((b % 2) == 1)) {
            long long k = a; 
            if (k > 1) {
                ans = k * k - 1; 
            } else {
                ans = 0;
            }
        } else {
            ans = a * b;
        }
    }
    else {
        long long a = r / 2;
        long long b = r - a;
        ans = a * b;
    }

    cout << ans << "\n";
    return 0;
}
