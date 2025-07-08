#include <bits/stdc++.h>
using namespace std;

struct SegMax {
    int n;
    vector<int> t;
    SegMax(int _n): n(_n), t(2*_n, 0) {}
    void update(int p, int val) {
        p += n;
        t[p] = max(t[p], val);
        for (p >>= 1; p > 0; p >>= 1)
            t[p] = max(t[p<<1], t[p<<1|1]);
    }
    int query(int l, int r) {
        if (l > r) return 0;
        int res = 0;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (!(r & 1)) res = max(res, t[r--]);
        }
        return res;
    }
};

struct SegPair {
    int n;
    vector<pair<int,int>> t;
    SegPair(int _n): n(_n), t(2*_n, {0,-1}) {}
    void assign(int p, pair<int,int> val) {
        p += n;
        t[p] = val;
        for (p >>= 1; p > 0; p >>= 1) {
            auto &L = t[p<<1], &R = t[p<<1|1];
            if (L.first > R.first || (L.first == R.first && L.second > R.second))
                t[p] = L;
            else
                t[p] = R;
        }
    }
    pair<int,int> query(int l, int r) {
        if (l > r) return {0,-1};
        pair<int,int> res = {0,-1};
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) {
                auto &c = t[l++];
                if (c.first > res.first || (c.first == res.first && c.second > res.second))
                    res = c;
            }
            if (!(r & 1)) {
                auto &c = t[r--];
                if (c.first > res.first || (c.first == res.first && c.second > res.second))
                    res = c;
            }
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long,long long>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(),
         [&](auto &L, auto &R){
             if (L.first != R.first) return L.first < R.first;
             return L.second < R.second;
         });

    vector<long long> allb(n);
    for(int i = 0; i < n; i++) allb[i] = p[i].second;
    sort(allb.begin(), allb.end());
    allb.erase(unique(allb.begin(), allb.end()), allb.end());
    int M = (int)allb.size();

    vector<int> idx(n);
    for(int i = 0; i < n; i++){
        idx[i] = int(lower_bound(allb.begin(), allb.end(), p[i].second) - allb.begin());
    }

    SegMax st_pref(M);
    vector<int> dp_pref(n);
    for(int i = 0; i < n; i++){
        long long bi = p[i].second;
        long long lo = bi - x;
        int l = int(lower_bound(allb.begin(), allb.end(), lo) - allb.begin());
        int r = idx[i];
        int best = st_pref.query(l, r);
        dp_pref[i] = best + 1;
        st_pref.update(idx[i], dp_pref[i]);
    }

    SegMax st_suf(M);
    vector<int> dp_suf(n);
    for(int i = n - 1; i >= 0; i--){
        long long bi = p[i].second;
        long long hi = bi + x;
        int l = idx[i];
        int r = int(upper_bound(allb.begin(), allb.end(), hi) - allb.begin()) - 1;
        int best = st_suf.query(l, r);
        dp_suf[i] = best + 1;
        st_suf.update(idx[i], dp_suf[i]);
    }

    vector< multiset<pair<int,int>> > ms(M);
    for(int j = 0; j < n; j++){
        ms[idx[j]].insert({ dp_suf[j], j });
    }
    SegPair st_tree(M);
    for(int c = 0; c < M; c++){
        if (!ms[c].empty()){
            auto it = prev(ms[c].end());
            st_tree.assign(c, *it);
        }
    }

    int best_len = 0, best_i = -1, best_j = -1;
    for(int i = 0; i < n; i++){
        auto &S = ms[idx[i]];
        S.erase(S.find({ dp_suf[i], i }));
        if (S.empty())
            st_tree.assign(idx[i], {0,-1});
        else
            st_tree.assign(idx[i], *prev(S.end()));

        long long bi = p[i].second;
        long long hi = bi + 2*x;
        int l = int(lower_bound(allb.begin(), allb.end(), bi) - allb.begin());
        int r = int(upper_bound(allb.begin(), allb.end(), hi) - allb.begin()) - 1;

        auto qr = st_tree.query(l, r);
        int suf_val = qr.first;
        int j = qr.second;

        int cand = dp_pref[i] + 1 + suf_val;
        if (cand > best_len){
            best_len = cand;
            best_i = i;
            best_j = j;
        }
    }

    long long ai = p[best_i].first;
    long long bi = p[best_i].second;
    long long a_star = ai;
    long long b_star;
    if (best_j == -1) {
        b_star = bi;
    } else {
        long long bj = p[best_j].second;
        b_star = min(bj, bi + x);
    }

    cout << best_len << " " << a_star << " " << b_star << "\n";
    return 0;
}

