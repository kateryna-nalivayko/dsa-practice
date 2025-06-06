#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> countDigitsUpTo(ll N) {
    vector<ll> cnt(10, 0);
    if (N < 0) return cnt;
    ll factor = 1;
    while (N / factor > 0) {
        ll lower = N - (N / factor) * factor;
        ll current = (N / factor) % 10;
        ll higher = N / (factor * 10);
        for (int d = 0; d <= 9; d++) {
            cnt[d] += higher * factor;
        }
        for (int d = 0; d < current; d++) {
            cnt[d] += factor;
        }
        cnt[current] += lower + 1;
        cnt[0] -= factor;
        factor *= 10;
    }
    return cnt;
}

char digitAtPosition(ll pos) {
    ll length = 1;
    ll count = 9;
    ll start = 1;
    while (pos > length * count) {
        pos -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    ll num = start + (pos - 1) / length;
    int offset = (int)((pos - 1) % length);
    string s = to_string(num);
    return s[offset];
}

void findNumberAndOffset(ll pos, ll &num, int &offset) {
    ll length = 1;
    ll count = 9;
    ll start = 1;
    while (pos > length * count) {
        pos -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }
    num = start + (pos - 1) / length;
    offset = (int)((pos - 1) % length);
}

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ll n, p, m;
    int d;
    cin >> n >> p >> m >> d;

    string A;
    for (ll pos = n; pos <= p; pos++) {
        A.push_back(digitAtPosition(pos));
    }
    cout << A << "\n";

    ll num_start, num_end;
    int offset_start, offset_end;
    findNumberAndOffset(n, num_start, offset_start);
    findNumberAndOffset(m, num_end, offset_end);

    vector<ll> freq(10, 0);

    if (num_start == num_end) {
        string s = to_string(num_start);
        for (int i = offset_start; i <= offset_end; i++) {
            int dig = s[i] - '0';
            freq[dig]++;
        }
    } else {
        {
            string s = to_string(num_start);
            int len = (int)s.size();
            for (int i = offset_start; i < len; i++) {
                int dig = s[i] - '0';
                freq[dig]++;
            }
        }
        {
            string s = to_string(num_end);
            for (int i = 0; i <= offset_end; i++) {
                int dig = s[i] - '0';
                freq[dig]++;
            }
        }
        ll L = num_start + 1;
        ll R = num_end - 1;
        if (L <= R) {
            vector<ll> cntR = countDigitsUpTo(R);
            vector<ll> cntL = countDigitsUpTo(L - 1);
            for (int dgt = 0; dgt <= 9; dgt++) {
                freq[dgt] += cntR[dgt] - cntL[dgt];
            }
        }
    }

    ll prod_mod = 1 % d;
    for (int dig = 1; dig <= 9; dig++) {
        if (freq[dig] > 0) {
            prod_mod = (prod_mod * modPow(dig, freq[dig], d)) % d;
        }
    }
    cout << prod_mod << "\n";

    for (int dig = 0; dig <= 9; dig++) {
        cout << freq[dig] << (dig < 9 ? ' ' : '\n');
    }

    return 0;
}
