#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    long long m;
    if (scanf("%d %d %lld", &n, &x, &m) != 3) return 0;
    vector<int> B;
    for (int i = 1; i <= n; i++){
        long long a;
        scanf("%lld", &a);
        if (a > m) B.push_back(i);
    }
    if (B.empty()){
        printf("0\n\n");
        return 0;
    }
    vector<int> ans;
    int prevL = -1e9, t = B.size(), idx = 0;
    while (idx < t){
        int bi = B[idx];
        int lb_prev = prevL < 0 ? 1 : prevL + x;
        int L = min(bi, n - x + 1);
        if (L < max(lb_prev, bi - x + 1)){
            printf("-1\n");
            return 0;
        }
        ans.push_back(L);
        prevL = L;
        int coverR = L + x - 1;
        while (idx < t && B[idx] <= coverR) idx++;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++){
        if (i) putchar(' ');
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
