#include <iostream>
using namespace std;

long long findLastNumber(long long n) {
   
    long long result = 1;
    while (result * 2 <= n) {
        result *= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    
    cout << findLastNumber(n) << endl;
    
    return 0;
}