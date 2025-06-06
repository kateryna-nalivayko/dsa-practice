#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, s;
    cin >> n >> p >> s;

    unsigned long long dp[31][31] = {}; 
    dp[0][0] = 1;

    for (int pos = 1; pos <= n; pos++) {
        for (int sum = 0; sum <= s; sum++) {
            if (dp[pos-1][sum] == 0) continue;
            int startDigit = (pos == 1 ? 1 : 0);
            for (int d = startDigit; d < p; d++) {
                if (sum + d > s) break;
                dp[pos][sum + d] += dp[pos-1][sum];
            }
        }
    }

    cout << dp[n][s] << "\n";
    return 0;
}
