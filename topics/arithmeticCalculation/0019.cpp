#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int N, Q, K;
    cin >> N >> Q >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    while (Q--) {
        int L1, R1, L2, R2;
        cin >> L1 >> R1 >> L2 >> R2;
        // Переводимо в 0‐based
        --L1; --R1; --L2; --R2;
        
        // Щоб менше вставок у множину, завжди обробляємо коротший інтервал першим
        if (R1 - L1 > R2 - L2) {
            swap(L1, L2);
            swap(R1, R2);
        }

        // Збираємо всі типи з першого інтервалу
        unordered_set<int> seen;
        for (int i = L1; i <= R1; ++i) {
            seen.insert(A[i]);
        }

        // Рахуємо, скільки з другого потрапляють у seen, уникаючи повторів
        int answer = 0;
        for (int i = L2; i <= R2; ++i) {
            auto it = seen.find(A[i]);
            if (it != seen.end()) {
                ++answer;
                seen.erase(it);
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
