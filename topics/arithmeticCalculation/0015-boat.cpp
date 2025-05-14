#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,h,w;
    cin >> k;
    vector<ll> val(k);
    for(int i = 0; i < k; i++){
        cin >> val[i];
    }
    cin >> h >> w;

    vector<vector<ll>> a(h, vector<ll>(w));
    string s;
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            a[h-1-i][j] = val[s[j] - 'a'];
        }
    }
    vector<vector<ll>> below(h, vector<ll>(w)), above(h, vector<ll>(w));

    for(int c = 0; c < w; c++){
        ll cur = LLONG_MIN;
        for(int r = 0; r < h; r++){
            cur = max(a[r][c], a[r][c] + (cur<0? 0: cur));
            below[r][c] = cur;
        }
    }
   
    for(int c = 0; c < w; c++){
        ll cur = LLONG_MIN;
        for(int r = h-1; r >= 0; r--){
            cur = max(a[r][c], a[r][c] + (cur<0? 0: cur));
            above[r][c] = cur;
        }
    }

    ll answer = LLONG_MIN;

    for(int r = 0; r < h; r++){
        ll pref = 0;        
        ll minPref = 0;     
        ll bestTB = LLONG_MIN; 

        for(int j = 0; j < w; j++){
            if(j > 0){
                ll towerNoHull = above[r][j-1] - a[r][j-1];
                bestTB = max(bestTB, towerNoHull - minPref);
            }

            pref += a[r][j];
            minPref = min(minPref, pref);

            if(bestTB != LLONG_MIN){
                ll tail = above[r][j] + below[r][j] - a[r][j];
                ll total = bestTB + pref + tail;
                answer = max(answer, total);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
