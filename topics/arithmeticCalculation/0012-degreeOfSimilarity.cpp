/*Stepan defines the degree of similarity between two strings of uppercase Latin letters as the number of neighboring pairs of elements from the first string that appear in the second string.For example, let's consider two strings ABBACAB and BCABB. The first string has the following pairs: AB, BB, BA, AC, CA, AB. Accordingly, from the given pairs of the first string, 
four pairs AB, BB, CA, AB are found in the second string.Help Stepan find the degree of similarity between two given strings.*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
  
    bool seen[26][26] = {};
    for (int i = 0; i + 1 < (int)t.size(); i++) {
        seen[t[i] - 'A'][t[i+1] - 'A'] = true;
    }
  
    int answer = 0;
    for (int i = 0; i + 1 < (int)s.size(); i++) {
        if (seen[s[i] - 'A'][s[i+1] - 'A'])
            answer++;
    }
    
    cout << answer;
    return 0;
}
