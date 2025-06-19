/*Due to the dissatisfaction of some participants regarding the regulations of the LKS, Valentin Ivanovich decided to gather an authoritative jury in order to make changes to the LKS regulations. To this end, Valentin Ivanovich organized a blitz tournament in sports programming (each round is held only between two participants, something similar to a chess tournament) among the jury members,
 which attracted N participants from all over Ukraine. Each participant has their own 'jury member rating.' It is clear that for such a prestigious tournament, Valentin Ivanovich does not allow participants with a negative rating. The authority of the jury is determined by the total rating of its members. However, Valentin Ivanovich understood that it is not feasible to invite all jury members to the selections - otherwise, 
 they would get bogged down in disputes, and no final decision would be made. But in order to meet all the requirements of modernity, he needs to justify his choice before the public, specifically – it should be as authoritative as possible (the highest) ranked jury. Moreover, since the jury members are vulnerable individuals, it should also be prevented that among the invited jury members for the selection there are those 
 who have lost to a participant in the tournament who did not receive an invitation. Write a program that will help Valentin Ivanovich choose the most authoritative jury that will meet all the demands of the harsh political life of computer scientists. It is guaranteed that such a jury always exists.*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
bitset<MAXN> lose[MAXN];

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0, u, v; i < M; ++i) {
        cin >> u >> v;
        --u; --v;
        lose[u].set(v);
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (lose[i].test(k)) {
                lose[i] |= lose[k];
            }
        }
    }
    long long best = LLONG_MAX;
    int start = 0;
    for (int i = 0; i < N; ++i) {
        long long sum = A[i];
        for (int j = 0; j < N; ++j) {
            if (lose[i].test(j)) {
                sum += A[j];
            }
        }
        if (sum < best) {
            best = sum;
            start = i;
        }
    }
    vector<int> jury;
    for (int i = 0; i < N; ++i) {
        if (i != start && !lose[start].test(i)) {
            jury.push_back(i + 1);
        }
    }
    cout << jury.size() << "\n";
    for (int x : jury) {
        cout << x << "\n";
    }
    return 0;
}
