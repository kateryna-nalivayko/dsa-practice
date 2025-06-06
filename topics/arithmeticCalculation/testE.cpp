#include <bits/stdc++.h>
using namespace std;

// Fenwick tree that stores (value, index) and supports
// prefix‐max queries and point updates.
struct Fenwick {
    int n;
    vector<pair<int,int>> f;
    Fenwick(int _n): n(_n), f(n+1, make_pair(0,0)) {}
    // update position i to max(current, v)
    void update(int i, pair<int,int> v) {
        for(; i<=n; i+=i&-i)
            if (v.first > f[i].first)
                f[i] = v;
    }
    // query max over [1..i]
    pair<int,int> query(int i) {
        pair<int,int> res = {0,0};
        for(; i>0; i-=i&-i)
            if (f[i].first > res.first)
                res = f[i];
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    // Read intervals, store as (r, l, original_index)
    vector<tuple<long long,long long,int>> A(n);
    for(int i=0; i<n; i++){
        long long l,r;
        cin >> l >> r;
        A[i] = make_tuple(r,l,i+1);
    }
    // Sort by end‐time ascending
    sort(A.begin(), A.end());

    // Extract into 1‐based arrays
    vector<long long> r(n+1), l(n+1);
    vector<int>  orig(n+1);
    for(int i=1; i<=n; i++){
        r[i]    = get<0>(A[i-1]);
        l[i]    = get<1>(A[i-1]);
        orig[i] = get<2>(A[i-1]);
    }

    // p[i]       = max j<i with r[j] <= l[i]
    // p_break[i] = max j<i with r[j] <= l[i] - t
    vector<int> p(n+1), p_break(n+1);
    for(int i=1; i<=n; i++){
        // r[j] <= l[i]
        int j = int(upper_bound(r.begin()+1, r.begin()+n+1, l[i]) - (r.begin()+1));
        p[i] = min(j, i-1);

        // r[j] <= l[i] - t
        long long need = l[i] - t;
        j = int(upper_bound(r.begin()+1, r.begin()+n+1, need) - (r.begin()+1));
        p_break[i] = min(max(j,0), i-1);
    }

    Fenwick fenw0(n), fenw1(n);
    vector<int> DP0(n+1), DP1(n+1),
                par0(n+1), par1(n+1);
    vector<char> usedBreak(n+1,0);

    int bestVal = 0, bestK = 0;

    for(int i=1; i<=n; i++){
        // ==== DP0 (no break yet) ====
        // DP0[i] = 1 + max{ DP0[j] : j <= p[i] }
        auto q0 = fenw0.query(p[i]);
        DP0[i]   = q0.first + 1;
        par0[i]  = q0.second;         // store which j gave the max
        fenw0.update(i, {DP0[i], i});

        // ==== DP1 (break used) ====
        // two ways to enter/continue DP1:
        //  1) break happens at this step: DP0[j] + 1  (j <= p_break[i])
        //  2) continue after-break:   DP1[j] + 1  (j <= p[i])
        auto qb = fenw0.query(p_break[i]);
        int val1 = (qb.first>=1 ? qb.first+1 : 0);
        int from1 = qb.second;

        auto q1 = fenw1.query(p[i]);
        int val2 = (q1.first>=1 ? q1.first+1 : 0);
        int from2 = q1.second;

        if(val1 >= val2){
            DP1[i]      = val1;
            par1[i]     = from1;
            usedBreak[i]= 1;
        } else {
            DP1[i]      = val2;
            par1[i]     = from2;
            usedBreak[i]= 0;
        }
        if(DP1[i]>0){
            fenw1.update(i, {DP1[i], i});
            if(DP1[i] > bestVal){
                bestVal = DP1[i];
                bestK   = i;
            }
        }
    }

    // If no valid schedule with at least one break + two matches
    if(bestVal < 2){
        cout << -1 << "\n";
        return 0;
    }

    // Reconstruct the chain:
    // 1) Walk back in DP1 from bestK down to the node where the break happened
    vector<int> after_rev;
    int cur = bestK;
    while(true){
        after_rev.push_back(cur);
        if(usedBreak[cur]) break;
        cur = par1[cur];
    }
    // cur is the first post-break interval.  par1[cur] is the last pre-break DP0 node
    int breakFrom = par1[cur];

    // 2) Reconstruct the DP0 chain ending at breakFrom
    vector<int> before;
    int c0 = breakFrom;
    while(c0){
        before.push_back(c0);
        c0 = par0[c0];
    }
    reverse(before.begin(), before.end());

    // 3) Build the after-break segment in forward order
    vector<int> after;
    for(auto it = after_rev.rbegin(); it!=after_rev.rend(); ++it){
        after.push_back(*it);
    }

    // 4) Combine and remap to original indices
    vector<int> ans;
    ans.reserve(before.size() + after.size());
    for(int x: before) ans.push_back(orig[x]);
    for(int x: after ) ans.push_back(orig[x]);

    // Output
    cout << bestVal << "\n";
    for(int i=0; i<ans.size(); i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
