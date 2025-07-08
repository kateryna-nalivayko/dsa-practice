#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;
using ll   = long long;
using u128 = unsigned __int128;

bool can_place(ll n, ll a, ll b, ll w, ll h, ll d) {
    ll A = a + 2*d;
    ll B = b + 2*d;

    ll cnt1 = (A > 0 ? w / A : 0) * (B > 0 ? h / B : 0);
    if ((u128)cnt1 >= (u128)n) return true;

    ll cnt2 = (B > 0 ? w / B : 0) * (A > 0 ? h / A : 0);
    if ((u128)cnt2 >= (u128)n) return true;

    return false;
}

int main() {
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    ll maxd_w = (w > a ? (w - a) / 2 : 0);
    ll maxd_h = (h > b ? (h - b) / 2 : 0);
    ll high = min(maxd_w, maxd_h);
    ll low = 0;

    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        if (can_place(n, a, b, w, h, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << "\n";
    return 0;
}
