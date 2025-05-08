/*The lady generously gave away a pocket full of 5, 10, 20, and 50 kopeck coins, and when she has to pay any amount, she chooses
her coins in such a way as to use the minimum possible number of coins. Your task is to write a program that, given the number of 5, 10, 20, and 50 kopeck coins in Lady's pocket, determines the
number of coins of each denomination and the total number of coins used so that the total number of coins she can use is minimal. Note that Lady will not always be able to pay the required amount of money*/

#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll c5, c10, c20, c50, S;
    cin >> c5 >> c10 >> c20 >> c50 >> S;
   
    ll c[4] = { c50, c20, c10, c5 };
    int d[4]  = { 50,  20,  10,  5  };
    ll used[4] = {0,0,0,0};

    for (int i = 0; i < 4; ++i) {
        ll take = S / d[i];
        if (take > c[i]) take = c[i];
        used[i] = take;
        S -= take * d[i];
    }

    if (S != 0) {
        cout << -1;
    } 
    else {
        ll total = used[0] + used[1] + used[2] + used[3];
        cout << used[3] << " "<< used[2] << " "<< used[1] << " "<< used[0] << " "<< total;
    }
    return 0;
}
