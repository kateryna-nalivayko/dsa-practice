#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXBIT = 31;

int main() {
    int t;
    cin >> t;
    while (t--) {
        const ll SHIFT = 1000000010LL;
        cout << "? " << SHIFT << " " << SHIFT << "\n";
        cout.flush();
        int _dummy;
        cin >> _dummy;

        ll X_bits = 0;
        ll Y_bits = 0;

        for (int k = 0; k < MAXBIT; k++) {
            ll pow2k = (1LL << k);
            ll pow2k1 = (1LL << (k + 1));

            cout << "? " << pow2k << " " << pow2k << "\n";
            cout.flush();
            int R1;
            cin >> R1;
            ll G1 = (ll)R1 - 1;

            cout << "? " << -pow2k << " " << -pow2k << "\n";
            cout.flush();
            int R1b;
            cin >> R1b;

            if ((G1 % pow2k1) == 0) {
                continue;
            }

            cout << "? " << pow2k << " " << 0 << "\n";
            cout.flush();
            int R2;
            cin >> R2;
            ll G2 = (ll)R2 - 1;

            cout << "? " << -pow2k << " " << 0 << "\n";
            cout.flush();
            int R2b;
            cin >> R2b;

            bool Xk_is_zero;
            if ((G2 % pow2k1) == 0) {
                Xk_is_zero = true;
            } else {
                Xk_is_zero = false;
            }

            bool Yk_is_zero = false;
            if (!Xk_is_zero) {
                cout << "? " << 0 << " " << pow2k << "\n";
                cout.flush();
                int R3;
                cin >> R3;
                ll G3 = (ll)R3 - 1;

                cout << "? " << 0 << " " << -pow2k << "\n";
                cout.flush();
                int R3b;
                cin >> R3b;

                if ((G3 % pow2k1) == 0) {
                    Yk_is_zero = true;
                } else {
                    Yk_is_zero = false;
                }
            } else {
                Yk_is_zero = false;
            }

            if (!Xk_is_zero) {
                X_bits |= pow2k;
            }
            if (!Yk_is_zero) {
                Y_bits |= pow2k;
            }
        }

        ll X_final = X_bits;
        ll Y_final = Y_bits;
        ll x0 = X_final - SHIFT;
        ll y0 = Y_final - SHIFT;

        cout << "! " << x0 << " " << y0 << "\n";
        cout.flush();

        int verdict;
        cin >> verdict;
    }
    return 0;
}
