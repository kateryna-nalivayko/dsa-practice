#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

string dec_str(const string &s) {
    string t = s;
    int i = t.size() - 1;
    while (i >= 0) {
        if (t[i] > '0') {
            t[i]--;
            break;
        } else {
            t[i] = '9';
            i--;
        }
    }
    if (t[0] == '0' && t.size() > 1) {
        t.erase(t.begin());
    }
    return t;
}

string S;
ll dp[105][11][2][2];

ll dfs(int pos, int last, int tight, int leading) {
    if (pos == (int)S.size()) {
        return 1;
    }
    ll &res = dp[pos][last][tight][leading];
    if (res != -1) return res;
    res = 0;
    int maxd = tight ? (S[pos] - '0') : 9;
    for (int d = 0; d <= maxd; d++) {
        int nt = tight && (d == maxd);
        if (leading && d == 0) {
            res = (res + dfs(pos+1, 0, nt, 1)) % MOD;
        } else {
            if (d < last) continue;
            res = (res + dfs(pos+1, d, nt, 0)) % MOD;
        }
    }
    return res;
}

ll countUpTo(const string &s) {
    S = s;
    for (int i = 0; i < (int)S.size(); i++)
        for (int l = 0; l < 11; l++)
            for (int t = 0; t < 2; t++)
                for (int z = 0; z < 2; z++)
                    dp[i][l][t][z] = -1;
    return dfs(0, 0, 1, 1);
}

int main() {
    string L, R;
    cin >> L >> R;
    string Lm = dec_str(L);
    ll cntR = countUpTo(R);
    ll cntL = (Lm == "0" ? 1 : countUpTo(Lm));
    ll ans = (cntR - cntL + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
