#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int p = n / 2;
    string U, V;
    U.reserve(p);
    V.reserve(p);
    for(int i = 0; i < n; i += 2) U.push_back(s[i]);
    for(int i = 1; i < n; i += 2) V.push_back(s[i]);
    string UU = U + U, VV = V + V;
    ull base = 1315423911ULL;
    vector<ull> powP(p+1);
    powP[0] = 1;
    for(int i = 1; i <= p; i++) powP[i] = powP[i-1] * base;
    vector<ull> prefU(2*p+1), prefV(2*p+1);
    for(int i = 0; i < 2*p; i++) prefU[i+1] = prefU[i] * base + (unsigned char)UU[i];
    for(int i = 0; i < 2*p; i++) prefV[i+1] = prefV[i] * base + (unsigned char)VV[i];
    vector<ull> H(n);
    for(int r = 0; r < p; r++){
        ull hU = prefU[r+p] - prefU[r] * powP[p];
        ull hV = prefV[r+p] - prefV[r] * powP[p];
        H[2*r] = hU;
        H[2*r+1] = hV;
    }
    vector<ull> D = H;
    sort(D.begin(), D.end());
    D.erase(unique(D.begin(), D.end()), D.end());
    int m = D.size();
    vector<int> id(n);
    for(int i = 0; i < n; i++){
        id[i] = lower_bound(D.begin(), D.end(), H[i]) - D.begin();
    }
    vector<long long> freq(m);
    for(int i = 0; i < n; i++) freq[id[i]]++;
    vector<pair<int,int>> P;
    P.reserve(n);
    for(int i = 0; i < n; i++){
        int j = (i + 1 == n ? 0 : i + 1);
        P.emplace_back(id[i], id[j]);
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    long long count_old = 0;
    for(auto &pr : P){
        count_old += freq[pr.first] * freq[pr.second];
    }
    long long total = 1LL * n * n;
    cout << (total - count_old);
    return 0;
}
