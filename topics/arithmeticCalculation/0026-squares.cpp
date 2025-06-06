#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    string ks = to_string(k);
    int digit_k = ks[0] - '0';

    auto repeated = [&](int d, int length, long long limit) {
        long long rep = 0;
        for (int i = 0; i < length; i++) {
            rep = rep * 10 + 1;
            if (rep > limit) return -1LL;
        }
        long long val = rep * d;
        if (val > limit) return -1LL;
        return val;
    };

    long long answer = 0;

    for (int d = 1; d < digit_k; d++) {
        int length = 1;
        while (true) {
            long long val = repeated(d, length, n);
            if (val < 0) break;
            answer++;
            length++;
        }
    }

    int length = 1;
    while (true) {
        long long val = repeated(digit_k, length, k);
        if (val < 0) break;
        answer++;
        length++;
    }

    cout << answer << "\n";
    return 0;
}
