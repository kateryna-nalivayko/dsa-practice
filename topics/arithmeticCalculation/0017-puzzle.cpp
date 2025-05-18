#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string s2 = S + S;
    int n2 = s2.size();

    vector<int> sa(n2), r(n2), tmp(n2);
    for (int i = 0; i < n2; i++) {
        sa[i] = i;
        r[i] = s2[i];
    }
    for (int k = 1; k < n2; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (r[i] != r[j]) return r[i] < r[j];
            int ri = (i + k < n2 ? r[i + k] : -1);
            int rj = (j + k < n2 ? r[j + k] : -1);
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n2; i++) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        r = tmp;
    }

    vector<int> order;
    order.reserve(N);
    for (int x : sa) {
        if (x < N) order.push_back(x);
    }
    vector<int> rankOnP(N);
    for (int i = 0; i < N; i++) {
        rankOnP[order[i]] = i;
    }

    auto can = [&](int th) {
        vector<pair<int,int>> segs;
        for (int i = 0; i < N; i++) {
            if (rankOnP[i] >= th) {
                int a = i;
                int b = i + K - 1;
                if (b < N) {
                    segs.emplace_back(a, b);
                } else {
                    segs.emplace_back(a, N - 1);
                    segs.emplace_back(0, b % N);
                }
            }
        }
        if (segs.empty()) return false;
        sort(segs.begin(), segs.end());
        int idx = 0, covered = -1, best = -1;
        while (idx < (int)segs.size() && segs[idx].first <= 0) {
            best = max(best, segs[idx].second);
            idx++;
        }
        if (best < 0) return false;
        covered = best;
        while (covered < N - 1) {
            int nxt = covered;
            while (idx < (int)segs.size() && segs[idx].first <= covered + 1) {
                nxt = max(nxt, segs[idx].second);
                idx++;
            }
            if (nxt == covered) return false;
            covered = nxt;
        }
        return true;
    };

    int low = 0, high = N - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (can(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int start = order[ans];
    for (int i = 0; i < K; i++) {
        cout << S[(start + i) % N];
    }
    cout << "\n";
    return 0;
}
