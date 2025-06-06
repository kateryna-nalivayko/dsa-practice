#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a1, a2;
    cin >> a1 >> a2;
    int L = a2 - a1 + 1;
    vector<int> rem(L), cnt_pf(L), distinct_pf(L);
    for (int i = 0; i < L; i++) {
        rem[i] = a1 + i;
        cnt_pf[i] = 0;
        distinct_pf[i] = 0;
    }

    int limit = int(floor(sqrt(a2))) + 1;
    vector<char> is_prime_small(limit + 1, true);
    is_prime_small[0] = false;
    is_prime_small[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (!is_prime_small[i]) continue;
        for (int j = i * i; j <= limit; j += i) {
            is_prime_small[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime_small[i]) primes.push_back(i);
    }

    for (int p : primes) {
        int start = (a1 + p - 1) / p * p;
        if (start < p * 1LL * p) {
            start = p * p;
        }
        for (int x = start; x <= a2; x += p) {
            int idx = x - a1;
            if (rem[idx] % p == 0) {
                distinct_pf[idx]++;
                while (rem[idx] % p == 0) {
                    rem[idx] /= p;
                    cnt_pf[idx]++;
                }
            }
        }
    }

    for (int i = 0; i < L; i++) {
        if (rem[i] > 1) {
            distinct_pf[i]++;
            cnt_pf[i]++;
        }
    }

    int count_div2or3 = 0;
    int count_primes   = 0;
    int count_two_diff = 0;
    int count_three4   = 0;

    for (int i = 0; i < L; i++) {
        int x = a1 + i;
        if (x % 2 == 0 || x % 3 == 0) {
            count_div2or3++;
        }
        if (x >= 2 && cnt_pf[i] == 1 && distinct_pf[i] == 1) {
            count_primes++;
        }
        if (cnt_pf[i] == 2 && distinct_pf[i] == 2) {
            count_two_diff++;
        }
        if (cnt_pf[i] == 3 || cnt_pf[i] == 4) {
            count_three4++;
        }
    }

    cout << count_div2or3 << "\n";
    cout << count_primes   << "\n";
    cout << count_two_diff << "\n";
    cout << count_three4   << "\n";

    return 0;
}
