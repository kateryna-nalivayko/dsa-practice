/*Stepan is a referee at a hypercheckers championship. Three
players participate in each hypercheckers game. During the game, each player scores a positive integer number of points. If, at the end of the
game, the first player has scored a points, the second player has scored b points, and the third player has scored c points, then we say that the game ended with the score a : b : c.
Stepan knows that the rules of hypercheckers are designed in such a way that as a result of the game, the scores of any two players differ by no more than k times.
After the match, Stepan shows his result by placing three cards with the players' scores
on a special board. To do this, he has a set of n cards with the numbers x1, x2, …, xn written on them.
To find out how prepared he is for the championship, Stepan wants to understand how many
different score options he can show on the board using the available cards.
He needs to write a program that, given a given number k and the values ​​of the numbers on Stepan's cards, determines the number of different counting options that Stepan can show on the board.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<ll> arr;
    vector<int> freq;
    arr.reserve(n);
    freq.reserve(n);
    for (int i = 0; i < n; ) {
        ll v = x[i];
        int c = 0;
        while (i < n && x[i] == v) {
            ++c; ++i;
        }
        arr.push_back(v);
        freq.push_back(c);
    }
    int m = arr.size();
    ll equal_triples = 0;
    for (int i = 0; i < m; ++i) {
        if (freq[i] >= 3) equal_triples++;
    }
    ll double_triples = 0;
    ll distinct_triples = 0;
    int hi = 0, lo = 0;
    for (int i = 0; i < m; ++i) {
        while (hi + 1 < m && arr[hi+1] <= arr[i] * k) {
            ++hi;
        }
        ll len = hi - i + 1;
        if (len >= 3) {
            ll t = len - 1;
            distinct_triples += t * (t - 1) / 2;
        }
        if (freq[i] >= 2) {
            ll lowVal = (arr[i] + k - 1) / k;
            while (lo < m && arr[lo] < lowVal) {
                ++lo;
            }
            ll count_q = hi - lo + 1;
            ll count_sv = count_q - 1;
            double_triples += count_sv;
        }
    }
    ll result = equal_triples + double_triples * 3 + distinct_triples * 6;
    cout << result << "\n";
    return 0;
}
