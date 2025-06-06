#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    long long total_extra = 0;
    int count_students = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mx) {
            total_extra += (mx - a[i]);
            count_students++;
        }
    }
    cout << total_extra << " " << count_students << "\n";
    return 0;
}
