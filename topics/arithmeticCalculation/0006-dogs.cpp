/*Lady's cottage is guarded by two dogs who often cause trouble. Every day, Lady is visited by the postman, the milkman, and the garbage collector. They know that dogs' behavior is quite predictable. When the day begins, one dog is aggressive for A minutes, then calm for B minutes. Similarly, the other dog is aggressive for C minutes, then calm for D minutes. Both
dogs repeat their behavior indefinitely - an aggressive period, then a calm period, then aggressive again, etc. Given the arrival times of the postman, the milkman, and the garbage collector, help Lady determine how many dogs
(none, one, or both) attack each of them. Note that the people arrive at minute k, not exactly k minutes later.*/

#include <iostream>
using namespace std;

bool isAggressive(int t, int a, int b) {
    int period = a + b;
    int r = t % period;
    if (r == 0) r = period;
    return r <= a;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int P, M, G;
    cin >> P >> M >> G;

    int cnt;
    cnt = 0;
    if ( isAggressive(P, A, B) ) ++cnt;
    if ( isAggressive(P, C, D) ) ++cnt;
    cout << cnt << "\n";
    cnt = 0;
    if ( isAggressive(M, A, B) ) ++cnt;
    if ( isAggressive(M, C, D) ) ++cnt;
    cout << cnt << "\n";

    cnt = 0;
    if ( isAggressive(G, A, B) ) ++cnt;
    if ( isAggressive(G, C, D) ) ++cnt;
    cout << cnt << "\n";

    return 0;
}
