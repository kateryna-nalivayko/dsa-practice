/*The lady found an ancient book of spells and decided to try one of them. Unfortunately, the book contains not the spell itself, but only its description. 
It is known that the spell is a correct sequence of brackets (PPD). A PPD is a string made up of the symbols "(" and ")". 
An empty string is a PPD. The concatenation of two possibly different PPDs is a PPD. A PPD taken in brackets is a PPD. 
Two brackets in a PPD are called matching if the substring that starts immediately after the first bracket and ends right before the second is a PPD. 
It is easy to prove that in any PPD of length n * 2, there are exactly n pairs of matching brackets. For simplicity, we will call them bracket pairs.
 It is known that the spell contains n pairs of brackets. Additionally, the multiset of distances between the brackets in each pair is known. 
 In other words, for each pair of brackets, the number ai - the number of symbols between them has been found. Now the lady is trying to reconstruct the spell. 
 Help her find any corresponding PPD, or report that such a PPD does not exist.*/

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 20;
int n;
int a[MAXN];
int cntDistance[41];
char resultArr[45];
vector<int> stackOpens;
bool foundSolution = false;

bool dfs(int pos, int opensUsed, int balance) {
    if (pos == 2*n) {
        if (balance == 0) {
            for (int d = 0; d <= 40; d++) {
                if (cntDistance[d] != 0) {
                    return false;
                }
            }
            foundSolution = true;
            return true;
        }
        return false;
    }
    if (foundSolution) return true;

    if (balance > 0) {
        int L = stackOpens.back();
        int d = pos - L - 1;
        if (d >= 0 && d <= 40 && cntDistance[d] > 0) {
            cntDistance[d]--;
            stackOpens.pop_back();
            resultArr[pos] = ')';
            if (dfs(pos+1, opensUsed, balance - 1)) {
                return true;
            }
            cntDistance[d]++;
            stackOpens.push_back(L);
        }
    }

    if (opensUsed < n) {
        resultArr[pos] = '(';
        stackOpens.push_back(pos);
        if (dfs(pos+1, opensUsed + 1, balance + 1)) {
            return true;
        }
        stackOpens.pop_back();
    }

    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(cntDistance, 0, sizeof(cntDistance));
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] <= 40) {
            cntDistance[a[i]]++;
        }
    }

    dfs(0, 0, 0);

    if (!foundSolution) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 0; i < 2*n; i++) {
            cout << resultArr[i];
        }
        cout << "\n";
    }
    return 0;
}
