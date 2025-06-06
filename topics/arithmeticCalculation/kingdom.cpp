#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int maxK = d;
    vector<bool> is_prime(maxK + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxK; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxK; j += i)
                is_prime[j] = false;
        }
    }

    long long answer = 0;
    for (int K = c; K <= d; ++K) {
        int need;
        if (K <= 1) {
            need = INT_MAX;               
        } else if (is_prime[K]) {
            need = 1;                      
        } else if (K % 2 == 0) {
            need = 2;                      
        } else if (K > 2 && is_prime[K - 2]) {
            need = 2;                     
        } else {
            need = 3;                    
        }

        if (need > b) continue;         
        int startN = max(a, need);
        answer += (b - startN + 1);      
    }

    cout << answer << "\n";
    return 0;
}
