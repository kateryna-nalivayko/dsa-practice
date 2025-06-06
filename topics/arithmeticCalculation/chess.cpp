#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    long long min_side = min(n, m);
    long long max_side = max(n, m);

    if (n == 1 || m == 1) {
        cout << max_side << endl;
    }
    else {
        cout << n + m + min_side - 2 << endl;
    }

    return 0;
}
