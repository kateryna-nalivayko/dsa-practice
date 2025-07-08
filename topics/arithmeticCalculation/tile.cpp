#include <iostream>
using namespace std;

int main() {
    long long M, X, Y, W, H;
    cin >> M >> X >> Y >> W >> H;

    unsigned long long i_min = X / M;
    unsigned long long i_max = (X + W - 1) / M;
    unsigned long long j_min = Y / M;
    unsigned long long j_max = (Y + H - 1) / M;

    unsigned long long x_cnt = (i_max >= i_min ? i_max - i_min + 1 : 0);
    unsigned long long y_cnt = (j_max >= j_min ? j_max - j_min + 1 : 0);

    cout << x_cnt * y_cnt << '\n';
    return 0;
}
