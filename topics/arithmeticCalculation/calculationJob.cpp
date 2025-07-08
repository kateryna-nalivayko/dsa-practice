#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> a(N+2), sum(N+3);
    vector<long long> mn(N+3);
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    sum[N+1] = 0;
    mn[N+1] = (long long)1e18;
    for(int i = N; i >= 1; i--){
        sum[i] = a[i] + sum[i+1];
        mn[i] = a[i] < mn[i+1] ? a[i] : mn[i+1];
    }
    long long bestNum = -1;
    long long bestDen = 1;
    for(int i = 2; i <= N-1; i++){
        long long num = sum[i] - mn[i];
        long long den = N - i;
        __int128 lhs = (__int128)num * bestDen;
        __int128 rhs = (__int128)bestNum * den;
        if(lhs > rhs){
            bestNum = num;
            bestDen = den;
        }
    }
    for(int i = 2; i <= N-1; i++){
        long long num = sum[i] - mn[i];
        long long den = N - i;
        __int128 lhs = (__int128)num * bestDen;
        __int128 rhs = (__int128)bestNum * den;
        if(lhs == rhs){
            cout << (i-1) << "\n";
        }
    }
    return 0;
}
