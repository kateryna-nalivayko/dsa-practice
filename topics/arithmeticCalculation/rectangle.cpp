#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x1a, y1a, x2a, y2a;
    int x1b, y1b, x2b, y2b;
    int x1c, y1c, x2c, y2c;
    cin >> x1a >> y1a >> x2a >> y2a;
    cin >> x1b >> y1b >> x2b >> y2b;
    cin >> x1c >> y1c >> x2c >> y2c;

    auto area = [&](int x1, int y1, int x2, int y2) {
        return (long long)(x2 - x1) * (y2 - y1);
    };
    auto intersect = [&](int xa1, int ya1, int xa2, int ya2,
                         int xb1, int yb1, int xb2, int yb2) {
        int ix = max(0, min(xa2, xb2) - max(xa1, xb1));
        int iy = max(0, min(ya2, yb2) - max(ya1, yb1));
        return (long long)ix * iy;
    };

    long long A = area(x1a, y1a, x2a, y2a)
                 - intersect(x1a, y1a, x2a, y2a, x1c, y1c, x2c, y2c);
    long long B = area(x1b, y1b, x2b, y2b)
                 - intersect(x1b, y1b, x2b, y2b, x1c, y1c, x2c, y2c);

    cout << (A + B) << "\n";
    return 0;
}
