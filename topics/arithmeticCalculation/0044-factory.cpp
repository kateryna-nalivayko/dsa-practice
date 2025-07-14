/*The confectionery factory's warehouse stores two types of pastries - croissants and eclairs. There are A croissants and B eclairs. 
There is an unlimited supply of gift boxes, and each box can only hold three pastries. At the same time, it is required that the box 
contains pastries of both types, meaning you can put two croissants and one eclair in one box or one croissant and two eclairs. Determine whether 
it is possible to pack all the pastries into the boxes and provide the corresponding arrangement of pastries in the boxes.*/

#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    long long x = 2 * A - B;
    long long y = 2 * B - A;

    if (x < 0 || y < 0 || x % 3 != 0 || y % 3 != 0) {
        cout << -1 << "\n";
    } else {
        cout << (x / 3) << " " << (y / 3) << "\n";
    }

    return 0;
}
