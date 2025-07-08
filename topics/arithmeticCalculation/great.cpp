#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;
    for(int i = 0; i < N; i++){
        long long x;
        cin >> x;
        if(x > max1){
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if(x > max2){
            max3 = max2;
            max2 = x;
        } else if(x > max3){
            max3 = x;
        }
        if(x < min1){
            min2 = min1;
            min1 = x;
        } else if(x < min2){
            min2 = x;
        }
    }
    long long p1 = max1 * max2 * max3;
    long long p2 = min1 * min2 * max1;
    if(p1 > p2)
        cout << max2 << ' ' << max1 << ' ' << max3;
    else
        cout << max1 << ' ' << min1 << ' ' << min2;
    return 0;
}
