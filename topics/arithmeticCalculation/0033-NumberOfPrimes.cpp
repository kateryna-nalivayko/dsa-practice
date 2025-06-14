#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> A(T), B(T);
    for (int i = 0; i < T; ++i) {
        cin >> A[i] >> B[i];
    }
    int global_max = 0;
    for (int i = 0; i < T; ++i) {
        int a = A[i], b = B[i];
        global_max = global_max < a ? a : global_max;
        global_max = global_max < b ? b : global_max;
        for (int k = 3; k <= 20; ++k) {
            int c = a + b;
            global_max = global_max < c ? c : global_max;
            a = b;
            b = c;
        }
    }
    vector<bool> is_prime(global_max + 1, true);
    if (global_max >= 0) is_prime[0] = false;
    if (global_max >= 1) is_prime[1] = false;
    for (int i = 2; i * i <= global_max; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= global_max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i < T; ++i) {
        int a = A[i], b = B[i], cnt = 0;
        if (is_prime[a]) ++cnt;
        if (is_prime[b]) ++cnt;
        for (int k = 3; k <= 20; ++k) {
            int c = a + b;
            if (is_prime[c]) ++cnt;
            a = b;
            b = c;
        }
        cout << cnt;
        if (i + 1 < T) cout << "\n";
    }
    return 0;
}
