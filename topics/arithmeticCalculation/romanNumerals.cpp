#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    if(!getline(cin,s)) return 0;
    int n = s.size();
    vector<string> thou = {"","M","MM","MMM"};
    vector<string> hund = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> ten  = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> one  = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    unordered_map<string,int> roman_val;
    roman_val.reserve(4096);
    for(int v = 1; v <= 3999; v++){
        int t = v/1000, h = (v%1000)/100, te = (v%100)/10, o = v%10;
        string r = thou[t] + hund[h] + ten[te] + one[o];
        roman_val[r] = v;
    }
    int maxLen = 0;
    for(auto &kv : roman_val)
        maxLen = max(maxLen, (int)kv.first.size());
    const long long INF = LLONG_MAX/4;
    vector<long long> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == INF) continue;
        int lim = min(maxLen, n - i);
        for(int l = 1; l <= lim; l++){
            string sub = s.substr(i, l);
            auto it = roman_val.find(sub);
            if(it != roman_val.end())
                dp[i + l] = min(dp[i + l], dp[i] + it->second);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
