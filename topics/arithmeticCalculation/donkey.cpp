#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;

int dp[21][21][21][21][4];
bool vis[21][21][21][21][4];

int di[4] = { 1,  0, -1, 0};
int dj[4] = { 0, -1,  0, 1};

int rec(int l, int r, int t, int b, int d) {
    if (l > r || t > b) return 0;
    if (vis[l][r][t][b][d]) 
        return dp[l][r][t][b][d];
    vis[l][r][t][b][d] = true;

    int best = 0;
    int sum = 0;
    int ci, cj;
   
    switch (d) {
        case 0: ci = t - 1; cj = r;   break; 
        case 1: ci = b;     cj = r + 1; break;  
        case 2: ci = b + 1; cj = l;   break;  
        default:ci = t;     cj = l - 1;  break;  
    }

    while (true) {
        ci += di[d];
        cj += dj[d];
        if (ci < t || ci > b || cj < l || cj > r) 
            break;
        sum += a[ci][cj];
        int nl = (d == 1 ? cj : (d == 2 ? l + 1 : l));
        int nr = (d == 3 ? cj : (d == 0 ? r - 1 : r));
        int nt = (d == 2 ? ci : (d == 3 ? t + 1 : t));
        int nb = (d == 0 ? ci : (d == 1 ? b - 1 : b));
        best = max(best, sum + rec(nl, nr, nt, nb, (d + 1) % 4));
    }

    return dp[l][r][t][b][d] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line); 
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        istringstream iss(line);
        int x;
        while (iss >> x) 
            a[i].push_back(x);
    }
    m = a[0].size();

    memset(vis, 0, sizeof(vis));

    int answer = INT_MIN;
    int prefix = 0;
    for (int j = 0; j < m; ++j) {
        prefix += a[0][j];
        answer = max(answer, prefix + rec(0, j, 1, n - 1, 0));
    }

    cout << answer << "\n";
    return 0;
}
