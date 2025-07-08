#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<long long> H(N);
        for(int i = 0; i < N; ++i) cin >> H[i];
        if(N == 1){
            cout << H[0] - 1 << " " << H[0];
        } else {
            long long K = LLONG_MAX;
            for(int i = 1; i < N; ++i){
                long long k = (H[i] - 1) / i;
                if(k < K) K = k;
            }
            long long H0 = LLONG_MAX;
            for(int i = 0; i < N; ++i){
                long long h = H[i] - K * (long long)i;
                if(h < H0) H0 = h;
            }
            cout << K << " " << H0;
        }
        if(T) cout << "\n";
    }
    return 0;
}
