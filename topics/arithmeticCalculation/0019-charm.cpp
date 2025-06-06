/*The lady, to avoid boredom, decided to count the number of magical triplets. A triplet of natural numbers a, b, 
and c (1 ≤ a < b < c ≤ n) is called magical if a · b, a · c, and b · c are squares of natural numbers. 
Help the lady find the number of magical triplets.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
    vector<int> sf(n + 1, 1);
    sf[1] = 1;
    for (int i = 2; i <= n; i++) {
        int p = spf[i];
        int m = i / p;
        if (m % p == 0) {
            sf[i] = sf[m / p];
        } else {
            sf[i] = sf[m] * p;
        }
    }

    vector<long long> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[ sf[i] ]++;
    }

    long long answer = 0;
    for (int d = 1; d <= n; d++) {
        if (cnt[d] >= 3) {
            long long c = cnt[d];
            answer += (c * (c - 1) * (c - 2)) / 6; 
        }
    }

    cout << answer << "\n";
    return 0;
}
