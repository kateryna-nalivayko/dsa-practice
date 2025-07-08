#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll D;
    cin >> N >> D;

    vector<ll> VB_B(N), VI_B(N);
    for(int i = 0; i < N; i++){
        cin >> VB_B[i] >> VI_B[i];
    }
    vector<ll> VB_I(N), VI_I(N);
    for(int j = 0; j < N; j++){
        cin >> VB_I[j] >> VI_I[j];
    }

    vector<int> dist_BI(N, -1), dist_JB(N, -1);
    set<pair<ll,int>> sb, si;
    for(int b = 0; b < N; b++){
        sb.insert({VI_B[b], b});
    }
    for(int j = 0; j < N; j++){
        si.insert({VB_I[j], j});
    }

    deque<pair<bool,int>> q;
    for(int b = 0; b < N; b++){
        if(VI_B[b] == 0){
            dist_BI[b] = 0;
            q.emplace_back(false, b);
            sb.erase({VI_B[b], b});
        }
    }
    for(int j = 0; j < N; j++){
        if(VB_I[j] == 0){
            dist_JB[j] = 0;
            q.emplace_back(true, j);
            si.erase({VB_I[j], j});
        }
    }

    while(!q.empty()){
        auto [isJB, u] = q.front();
        q.pop_front();
        if(!isJB){
            ll vb = VB_B[u];
            ll low = vb - D;
            ll high = vb;
            auto it = si.lower_bound({low, INT_MIN});
            while(it != si.end() && it->first <= high){
                int j = it->second;
                dist_JB[j] = dist_BI[u] + 1;
                q.emplace_back(true, j);
                auto it2 = it++;
                si.erase(it2);
            }
        } else {
            ll vi = VI_I[u];
            ll low = vi - D;
            ll high = vi;
            auto it = sb.lower_bound({low, INT_MIN});
            while(it != sb.end() && it->first <= high){
                int b = it->second;
                dist_BI[b] = dist_JB[u] + 1;
                q.emplace_back(false, b);
                auto it2 = it++;
                sb.erase(it2);
            }
        }
    }

    for(int b = 0; b < N; b++){
        if(dist_BI[b] < 0)
            cout << -1 << "\n";
        else
            cout << dist_BI[b] + 1 << "\n";
    }
    return 0;
}
