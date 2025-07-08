#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1000000007;
    mt19937_64 rng((ull)chrono::steady_clock::now().time_since_epoch().count());
    const ull B = (rng() | 1ULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> c(n+1);
        for (int i = 1; i <= n; i++) cin >> c[i];

        vector<vector<int>> g(n+1);
        vector<pair<int,int>> edges;
        edges.reserve(n-1);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            edges.emplace_back(u,v);
        }

        vector<int> vals(c.begin()+1, c.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<ull> tyhash(vals.size());
        for (size_t i = 0; i < vals.size(); i++) 
            tyhash[i] = rng();
        vector<ull> type_hash(n+1);
        for (int i = 1; i <= n; i++) {
            int id = lower_bound(vals.begin(), vals.end(), c[i]) - vals.begin();
            type_hash[i] = tyhash[id];
        }

        vector<int> parent(n+1), tin(n+1), tout(n+1);
        vector<ull> h_down(n+1), h_up(n+1), sum_down(n+1);
        int timer = 0;

        function<void(int,int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            tin[u] = ++timer;
            ull sum = 0;
            for (int v : g[u]) if (v != p) {
                dfs1(v, u);
                sum += h_down[v];
            }
            sum_down[u] = sum;
            h_down[u] = type_hash[u] ^ (sum * B);
            tout[u] = timer;
        };
        dfs1(1,0);

        function<void(int,int)> dfs2 = [&](int u, int p) {
            ull total = sum_down[u] + (p ? h_up[u] : 0ULL);
            for (int v : g[u]) if (v != p) {
                ull sum_ex = total - h_down[v];
                h_up[v] = type_hash[u] ^ (sum_ex * B);
                dfs2(v,u);
            }
        };
        h_up[1] = 0;
        dfs2(1,0);
        vector<ull> hv;
        hv.reserve(2*(n-1));
        for (auto &e : edges) {
            int u = e.first, v = e.second;
            ull huv = (parent[u]==v ? h_down[u] : h_up[u]);
            ull hvu = (parent[v]==u ? h_down[v] : h_up[v]);
            hv.push_back(huv);
            hv.push_back(hvu);
        }
        sort(hv.begin(), hv.end());
        hv.erase(unique(hv.begin(), hv.end()), hv.end());

        struct Edge { int to, hid, rev; };
        vector<vector<Edge>> adj(n+1);
        for (auto &e : edges) {
            int u = e.first, v = e.second;
            ull huv = (parent[u]==v ? h_down[u] : h_up[u]);
            ull hvu = (parent[v]==u ? h_down[v] : h_up[v]);
            int id_uv = lower_bound(hv.begin(), hv.end(), huv) - hv.begin();
            int id_vu = lower_bound(hv.begin(), hv.end(), hvu) - hv.begin();
            int iu = adj[u].size();
            int iv = adj[v].size();
            adj[u].push_back({v, id_uv, iv});
            adj[v].push_back({u, id_vu, iu});
        }

        vector<int> freq(hv.size());
        ll ans_cur = 0;
        for (int u = 2; u <= n; u++) {
            int hid = -1;
            for (auto &ed : adj[u]) if (ed.to == parent[u]) {
                hid = ed.hid; break;
            }
            ans_cur += freq[hid];
            freq[hid]++;
        }

        vector<ll> ans(n+1);
        ans[1] = ans_cur;

        function<void(int,int)> dfs_reroot = [&](int u, int p) {
            for (auto &ed : adj[u]) {
                int v = ed.to;
                if (v == p) continue;
                int hid_new = ed.hid;
                int hid_old = adj[v][ed.rev].hid;
                freq[hid_old]--;
                ans_cur -= freq[hid_old];
                ans_cur += freq[hid_new];
                freq[hid_new]++;
                ans[v] = ans_cur;
                dfs_reroot(v, u);
                freq[hid_new]--;
                ans_cur -= freq[hid_new];
                freq[hid_old]++;
                ans_cur += freq[hid_old]-1;
            }
        };
        dfs_reroot(1,0);

        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            cout << (ans[x] % MOD) << "\n";
        }
    }
    return 0;
}
