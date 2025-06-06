#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long t;
    if(!(cin >> n >> t)) return 0;

    vector<pair<long long,long long>> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;  // A[i] = {l_i, r_i}
    }

    // 1) Жадібний набір “до перерви”: сортуємо за r↑
    vector<int> orderR(n);
    iota(orderR.begin(), orderR.end(), 0);
    sort(orderR.begin(), orderR.end(),
         [&](int i, int j){ return A[i].second < A[j].second; });

    vector<long long> finish;    // часи закінчення відібраних “до”
    vector<int>       forw;      // їхні індекси (1-based)
    long long lastR = LLONG_MIN/2;
    for(int idx : orderR){
        if (A[idx].first >= lastR){
            finish.push_back(A[idx].second);
            forw.push_back(idx+1);
            lastR = A[idx].second;
        }
    }
    int fcnt = finish.size();

    // 2) Жадібний набір “після перерви”: сортуємо за l↓
    vector<int> orderL(n);
    iota(orderL.begin(), orderL.end(), 0);
    sort(orderL.begin(), orderL.end(),
         [&](int i, int j){ return A[i].first > A[j].first; });

    vector<long long> startv;    // часи початку відібраних “після”
    vector<int>       backw;     // їхні індекси (1-based)
    long long firstL = LLONG_MAX/2;
    for(int idx : orderL){
        if (A[idx].second <= firstL){
            startv.push_back(A[idx].first);
            backw.push_back(idx+1);
            firstL = A[idx].first;
        }
    }
    int bcnt = startv.size();

    // 3) Два вказівники: шукаємо max(i + j) з finish[i-1] + t <= startv[j-1]
    int ans = 0, bestI = 0, bestJ = 0;
    int j = bcnt;
    for(int i = 1; i <= fcnt; i++){
        long long breakTime = finish[i-1] + t;
        while(j > 0 && startv[j-1] < breakTime) 
            --j;
        if (j > 0 && i + j > ans){
            ans = i + j;
            bestI = i;
            bestJ = j;
        }
    }

    // Якщо не вдалося скласти хоча б дві ігри з перервою — виводимо -1
    if (ans < 2){
        cout << -1 << "\n";
        return 0;
    }

    // 4) Відновлюємо і виводимо розклад
    cout << ans << "\n";
    // спочатку bestI ігор “до”
    for(int i = 0; i < bestI; i++){
        cout << forw[i] << " ";
    }
    // потім bestJ ігор “після” у хронологічному порядку
    // (backw зібрано у зворотному хронологічному, тому ітеруємо назад)
    for(int k = bestJ - 1; k >= 0; k--){
        cout << backw[k] << " ";
    }
    cout << "\n";

    return 0;
}
