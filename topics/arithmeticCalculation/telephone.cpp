#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    if (n < 2) {
        cout << s;
        return 0;
    }
    vector<char> minChar(n);
    vector<int>  minPos(n);

    minChar[n-1] = s[n-1];
    minPos [n-1] = n-1;

    for(int i = n-2; i >= 0; --i) {
        if (s[i] < minChar[i+1]) {
            minChar[i] = s[i];
            minPos [i] = i;
        } else {
            minChar[i] = minChar[i+1];
            minPos [i] = minPos[i+1];
        }
    }

    bool swapped = false;
    for(int i = 0; i < n-1; ++i) {
        if (minChar[i+1] < s[i]) {
            int j = minPos[i+1];
            swap(s[i], s[j]);
            swapped = true;
            break;
        }
    }
    cout << s;
    return 0;
}
