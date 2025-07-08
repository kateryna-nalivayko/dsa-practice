/*Let's consider the string s, consisting of lowercase letters of the Latin alphabet.
 A substring of the string s is a string made up of one or more consecutive characters from the string s. 
 We denote W(s) as the set consisting of all possible substrings of the string s. For example, 
 W("abba") = {"a", "b", "ab", "ba", "bb", "abb", "bba", "abba"}. A subsequence of the string s is a string
that can be obtained from s by deleting any number of characters. We denote Y(s) as the set consisting of all 
possible subsequences of the string s. Similar to W(s), each subsequence of the string s is included in Y(s) 
exactly once, even if it can be obtained in multiple ways by deleting characters from the string s. Since any
substring of the string s is also a subsequence of it, the set Y(s) includes W(s) but may also contain other
strings. For example, Y("abba") = W("abba") ∪ {"aa", "aba"}. The symbol ∪ means the union of sets.
We will call the string s strange if W(s) = Y(s).Yes, for the string "abba", its weirdness equals 7, 
and any of its substrings, except for the whole string, is weird. You need to write a program that determines 
its weirdness for a given string s.*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
using namespace std;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    vector<pair<char,int>> runs;
    runs.reserve(n);
    char last = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == last) {
            cnt++;
        } else {
            runs.emplace_back(last, cnt);
            last = s[i];
            cnt = 1;
        }
    }
    runs.emplace_back(last, cnt);

    ull answer = 0;
    vector<int> max_run_len(26, 0);
    for (auto &r : runs) {
        int c = r.first - 'a';
        max_run_len[c] = max(max_run_len[c], r.second);
    }
    for (int c = 0; c < 26; c++) {
        answer += max_run_len[c];
    }

    int R = runs.size();
    vector<vector<pair<int,int>>> adj(26 * 26);
    for (int i = 0; i + 1 < R; i++) {
        int x = runs[i].first - 'a';
        int y = runs[i+1].first - 'a';
        adj[x * 26 + y].emplace_back(runs[i].second, runs[i+1].second);
    }

    for (int id = 0; id < 26 * 26; id++) {
        auto &vec = adj[id];
        if (vec.empty()) continue;
        int max_l1 = 0;
        for (auto &p : vec) {
            max_l1 = max(max_l1, p.first);
        }
        vector<int> best_l2_at(max_l1 + 1, 0);
        for (auto &p : vec) {
            best_l2_at[p.first] = max(best_l2_at[p.first], p.second);
        }
        int curr_max_l2 = 0;
        for (int p = max_l1; p >= 1; p--) {
            curr_max_l2 = max(curr_max_l2, best_l2_at[p]);
            answer += curr_max_l2;
        }
    }

    cout << answer << "\n";
    return 0;
}
