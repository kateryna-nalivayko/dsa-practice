/*There are three vases with candies on the table. In the left vase there are A candies, in the middle vase - V candies, in the right vase, respectively, C candies. Stepan eats one candy from the left vase, then - one candy from the middle vase, then from the right, middle, left, middle, right, middle, etc. (from left to right, then to the left, again to the right, etc.).
If Stepan wants to take a candy from a vase, and it is not there, then he gets upset and goes to bed. Determine how many candies Stepan will eat.*/

#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long x;

    if (A <= B / 2 && A <= C)
        x = A;
    else if (B / 2 <= A && B / 2 <= C)
        x = B / 2;
    else
        x = C;

    long long candiesEaten = x * 4;

    A -= x;
    B -= x * 2;
    C -= x;

    if(A > 0) {
        A--;
        candiesEaten++;
    } else {
        cout << candiesEaten << endl;
        return 0;
    }

    if (B > 0) {
        B--;         
        candiesEaten++; 
    } else {
        cout << candiesEaten << endl;
        return 0;
    }

    if (C > 0) {
        C--;
        candiesEaten++;
    } else {
        cout << candiesEaten << endl;
        return 0;
    }

    if (B > 0) {
        B--;
        candiesEaten++;
    }

    cout << candiesEaten << endl;
    return 0;
}