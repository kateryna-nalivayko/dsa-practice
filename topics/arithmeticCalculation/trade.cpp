#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

struct Line {
    ll m, b;
    ll eval(ll x) const { return m * x + b; }
};

bool is_bad(const Line &l1, const Line &l2, const Line &l3) {
    __int128 lhs = (__int128)(l2.b - l1.b) * (l2.m - l3.m);
    __int128 rhs = (__int128)(l3.b - l2.b) * (l1.m - l2.m);
    return lhs >= rhs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());

        vector<ll> pref(n+1, 0);
        for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + s[i-1];

        vector<ll> dp_prev(n+1, INF), dp_cur(n+1, INF);
        dp_prev[0] = 0;

        for (int j = 1; j <= k; j++) {
            fill(dp_cur.begin(), dp_cur.end(), INF);
            deque<Line> dq;
            for (int p = j-1; p < n; p++) {
                if (dp_prev[p] >= INF/2) continue;
                Line ln{ - (ll)p, dp_prev[p] + pref[p] };
                while (dq.size() >= 2 && is_bad(dq[dq.size()-2], dq[dq.size()-1], ln))
                    dq.pop_back();
                dq.push_back(ln);
            }
            for (int i = j; i <= n; i++) {
                ll x = s[i-1];
                while (dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x))
                    dq.pop_front();
                ll best = dq.front().eval(x);
                dp_cur[i] = i * x - pref[i] + best;
            }
            dp_prev.swap(dp_cur);
        }

        cout << dp_prev[n] << "\n";
    }

    return 0;
}
