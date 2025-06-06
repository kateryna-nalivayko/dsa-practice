#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];

    vector<bool> full(n, true), has(n, false);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if (g[i][j] == '.') full[j] = false; else has[j] = true;

    int c0 = 0;
    for (bool f : full) if (f) ++c0;

    int ans = -1;
    for (int p = 0; p < n; ++p) {
        if (!has[p]) continue;
        int missing = 0, broken = 0;
        for (int j = 0; j < n; ++j)
            if (g[p][j] == '.') {
                ++missing;
                if (full[j]) ++broken;
            }
        int cost = (n - c0) + missing + broken;
        if (ans < 0 || cost < ans) ans = cost;
    }

    cout << ans;
    return 0;
}
