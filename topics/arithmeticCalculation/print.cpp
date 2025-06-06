#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int maxCost = 2 * n + 5;
    int dpS = maxCost, dpD0 = maxCost, dpD1 = maxCost;

    if (x[0] == 1) {
        dpS  = 1; 
        dpD1 = 1;  
    }
    else if (x[0] == 2) {
        dpD0 = 1;  
    }
    else { 
        dpD1 = 1; 
        dpD0 = 2;  
        dpS  = 2;  
    }
    for(int i = 1; i < n; i++){
        int a = x[i];
        int nS = maxCost, nD0 = maxCost, nD1 = maxCost;

        if (a == 1) {
            nS  = min(nS, dpS);
            nS  = min(nS, dpD0 + 1);
            nS  = min(nS, dpD1 + 1);
            nD1 = min(nD1, dpS + 1);
            nD1 = min(nD1, dpD0);
            nD1 = min(nD1, dpD1 + 1);
        }
        else if (a == 2) {
            nD0 = min(nD0, dpS  + 1);
            nD0 = min(nD0, dpD0  );
            nD0 = min(nD0, dpD1 + 1);
        }
        else { 
            nD1 = min(nD1, dpS  + 1);
            nD1 = min(nD1, dpD0  );
            nD1 = min(nD1, dpD1 + 1);
            nD0 = min(nD0, dpS  + 1);
            nD0 = min(nD0, dpD0 + 2);
            nD0 = min(nD0, dpD1 + 2);
            nS  = min(nS, dpS  + 2);
            nS  = min(nS, dpD0 + 1);
            nS  = min(nS, dpD1 + 2);
        }

        dpS  = nS;
        dpD0 = nD0;
        dpD1 = nD1;
    }

    int answer = min({dpS, dpD0, dpD1});
    cout << answer << "\n";
    return 0;
}
