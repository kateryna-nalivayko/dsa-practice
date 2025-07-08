#include <bits/stdc++.h>
using namespace std;

string sub(const string& a, const string& b) {
    string A = a;
    string B(a.size() - b.size(), '0');
    B += b;
    int n = A.size(), carry = 0;
    string R(n, '0');
    for (int i = n-1; i >= 0; --i) {
        int d = (A[i] - '0') - (B[i] - '0') - carry;
        if (d < 0) { d += 10; carry = 1; }
        else        carry = 0;
        R[i] = char('0' + d);
    }
    auto p = R.find_first_not_of('0');
    return p == string::npos ? "0" : R.substr(p);
}
string div_int(const string& a, int b) {
    string R;
    long long rem = 0;
    for (char c : a) {
        rem = rem*10 + (c - '0');
        R.push_back(char('0' + rem / b));
        rem %= b;
    }
    auto p = R.find_first_not_of('0');
    return p == string::npos ? "0" : R.substr(p);
}

int main() {
    int N;
    cin >> N;              
    int denom = 10*N - 1;   

    for (int k = 1; ; ++k) {
        string num = to_string(N) + string(k, '0');
        string diff = sub(num, to_string(N*N));
        int rem = 0;
        for (char c : diff)
            rem = (rem*10 + (c - '0')) % denom;
        if (rem != 0) continue;
        string a = div_int(diff, denom);
        if ((int)a.size() == k && a[0] != '0') {
            cout << a << N << "\n";
            break;
        }
    }
    return 0;
}