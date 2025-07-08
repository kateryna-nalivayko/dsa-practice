/*In the possessions of the King of Potokolandia there is a straight road n kilometers long, on one side of which there is a huge forest.
The King of Potokolandia was inspired by the ideas of nature protection and decided to turn his
forest into a reserve.
But the sons began to resist: after all, they wanted to inherit these lands.
The king has three sons: the youngest, middle and eldest. The king decided that the reserve would not include the forest areas that he would leave to his sons as an inheritance.
When drawing up a will, the king wants the following conditions to be met for the plots: – each plot must have the shape of a square, the length of the side of which is expressed by a positive integer. One of the sides of each square must lie on the road.
Let the plots have dimensions a × a, b × b and c × c; – the sides of the squares must completely cover the road: the value a + b + c must
equal to n; – the plot of the youngest son must be strictly smaller than the plot of the middle son, and
the plot of the middle son must, in turn, be strictly smaller than the plot of the eldest son,
that is, the inequality a < b < c must hold; – the total area of ​​the plots a2 + b2 + c2 must be minimal.
It is necessary to write a program that, given the given length of the road, determines the sizes of the plots
that should be allocated to the king's sons.*/

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long m = n / 3;
    int r = n % 3;
    long long a, b, c;
    if (r == 0) {
        a = m - 1;
        b = m;
        c = m + 1;
    } else if (r == 1) {
        a = m - 1;
        b = m;
        c = m + 2;
    } else { // r == 2
        a = m - 1;
        b = m + 1;
        c = m + 2;
    }
    cout << a << " " << b << " " << c << "\n";
    return 0;
}
