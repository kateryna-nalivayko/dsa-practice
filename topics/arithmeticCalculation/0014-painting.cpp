#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);  

    int N, K;
    cin >> N >> K;

    vector<pair<ll,ll>> intervals;
    intervals.reserve(N);

    for (int i = 0; i < N; i++) {
        int Ci;
        cin >> Ci;
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        for (int j = 0; j < Ci; j++) {
            ll x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        intervals.emplace_back(mn, mx);
    }

    sort(intervals.begin(), intervals.end());
    priority_queue<ll> pq;
    ll answer = LLONG_MAX;

    for (int i = N - 1; i >= 0; i--) {
        ll Li = intervals[i].first;
        ll Ri = intervals[i].second;

        pq.push(Ri);
        if ((int)pq.size() > K) {
            pq.pop();
        }

        if ((int)pq.size() == K) {
            ll kth_min_R = pq.top();
            answer = min(answer, kth_min_R - Li);
        }
    }

    cout << answer << endl;
    return 0;
}
