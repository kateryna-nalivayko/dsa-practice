/*Bus stops are located every K meters from the beginning of the street, i.e. at distances of 0, K, 2K, 3K, etc. meters from the start. 
Stepan walked N meters from the beginning of the street, after which he got tired and wanted to sit on the bus. Determine how many meters 
Stepan needs to walk to the nearest stop.*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long K, N;
    cin >> K >> N;

    long long r = N % K;
    long long answer = min(r, K - r);

    cout << answer << "\n";
    return 0;
}

