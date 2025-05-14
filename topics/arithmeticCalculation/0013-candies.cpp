#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    unordered_map<long long,int> cnt;
    cnt.reserve(4);

    int l = 0, ans = 0;
    for (int r = 0; r < N; r++) {
        ++cnt[p[r]];
        while (cnt.size() > 2) {
            if (--cnt[p[l]] == 0) {
                cnt.erase(p[l]);
            }
            l++;
        }
        if (cnt.size() == 2) {
            ans = max(ans, r - l + 1);
        }
    }

    cout << ans << endl;
    return 0;
}
