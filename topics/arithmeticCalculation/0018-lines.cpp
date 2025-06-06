#include <bits/stdc++.h>
using namespace std;

// Перевіряє, чи можна з p (довжина m) "зішашлити" s (довжина n),
// тобто чи s є перемішуванням k = n/m копій p
bool is_shuffle_of_k(const string &s, const string &p) {
    int n = s.size(), m = p.size();
    if (n % m) return false;
    int k = n / m;

    // cnt[j] = кількість "копій" p, які вже
    // зчитали j символів (і чекають символ p[j])
    vector<int> cnt(m+1, 0);
    cnt[0] = k;

    for (char c : s) {
        bool assigned = false;
        // знаходимо найменший j, для якого p[j]==c і є копія на стадії j
        for (int j = 0; j < m; ++j) {
            if (cnt[j] > 0 && p[j] == c) {
                --cnt[j];
                ++cnt[j+1];
                assigned = true;
                break;
            }
        }
        if (!assigned) return false;
    }
    // якщо всі k копій дочиталися до кінця — успіх
    return cnt[m] == k;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> divs;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) divs.push_back(d);
    }
    sort(divs.begin(), divs.end());

    for (int m : divs) {
        vector<string> candidates;
        for (int i = 0; i + m <= n; ++i) {
            candidates.push_back(s.substr(i, m));
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        for (auto &p : candidates) {
            if (is_shuffle_of_k(s, p)) {
                cout << p << "\n";
                return 0;
            }
        }
    }
    cout << s << "\n";
    return 0;
}
