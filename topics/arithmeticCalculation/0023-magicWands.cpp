#include <bits/stdc++.h>
using namespace std;

struct Line {
    int m;
    long long S;
    long long I;
};

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> w(N), li(N), ci(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> li[i] >> ci[i];
    }

    vector<int> best0(W + 1, 0);
    for (int i = 0; i < N; i++) {
        if (ci[i] == 0 && w[i] <= W) {
            best0[w[i]] = max(best0[w[i]], li[i]);
        }
    }

    vector<long long> dp2(W + 1, 0);
    for (int weight = 1; weight <= W; weight++) {
        if (best0[weight] > 0) {
            long long val2 = 2LL * best0[weight];
            for (int j = weight; j <= W; j++) {
                dp2[j] = max(dp2[j], dp2[j - weight] + val2);
            }
        }
    }

    vector<long long> dp2_cur(W + 1);
    for (int idx = 0; idx < N; idx++) {
        if (ci[idx] == 0) continue;
        int wi = w[idx];
        long long li_i = li[idx];
        long long ci_i = ci[idx];
        if (wi > W) continue;

        long long Mi = (li_i - 1) / ci_i + 1;
        dp2_cur = dp2;

        for (int r = 0; r < wi; r++) {
            int K_max = (W - r) / wi;
            if (K_max < 0) continue;
            int T = (int)min<long long>(Mi, K_max);
            if (T <= 0) continue;

            static vector<long long> A2;
            A2.resize(K_max + 1);
            for (int m = 0; m <= K_max; m++) {
                A2[m] = dp2[r + m * wi];
            }

            deque<Line> dq;
            for (int k = 0; k <= K_max; k++) {
                int m = k;
                long long S_m = 2LL * ci_i * m;
                long long I_m = A2[m] - ci_i * (long long)m * m - m * (2LL * li_i + ci_i);
                Line newline = {m, S_m, I_m};
                while (dq.size() >= 2) {
                    Line &a = dq[dq.size() - 2];
                    Line &b = dq[dq.size() - 1];
                    Line &c = newline;
                    long long dI1 = b.I - a.I;
                    long long dS1 = b.S - c.S;
                    long long dI2 = c.I - b.I;
                    long long dS2 = a.S - b.S;
                    __int128 left  = (__int128)dI1 * dS1;
                    __int128 right = (__int128)dI2 * dS2;
                    if (left >= right) {
                        dq.pop_back();
                    } else break;
                }
                dq.push_back(newline);

                int m0 = k - T - 1;
                if (m0 >= 0 && !dq.empty() && dq.front().m == m0) {
                    dq.pop_front();
                }

                while (dq.size() >= 2) {
                    Line &f1 = dq[0];
                    Line &f2 = dq[1];
                    long long v1 = f1.S * k + f1.I;
                    long long v2 = f2.S * k + f2.I;
                    if (v1 <= v2) {
                        dq.pop_front();
                    } else break;
                }
                Line &best = dq.front();
                long long H2k = best.S * k + best.I;
                long long Ck2 = 2LL * li_i * k - ci_i * (1LL * k * k - k);
                long long B2k = H2k + Ck2;
                int j = r + k * wi;
                dp2_cur[j] = B2k;
            }
        }

        dp2.swap(dp2_cur);
    }

    long long best2 = 0;
    for (int j = 0; j <= W; j++) {
        best2 = max(best2, dp2[j]);
    }
    cout << (best2 / 2) << "\n";
    return 0;
}
