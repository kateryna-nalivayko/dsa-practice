#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m = s.size();

    long long ans = 1;
    for (char c : s) 
        ans *= (c - '0');

    for (int i = 0; i < m; ++i) {
        if (s[i] == '0') continue;          
        string t = s;
        t[i] = char(s[i] - 1);             
        for (int j = i + 1; j < m; ++j)
            t[j] = '9';                    

        int k = 0;
        while (k < m && t[k] == '0') 
            ++k;

        long long prod = 1;
        for (int j = k; j < m; ++j)
            prod *= (t[j] - '0');

        ans = max(ans, prod);
    }

    cout << ans << "\n";
    return 0;
}
