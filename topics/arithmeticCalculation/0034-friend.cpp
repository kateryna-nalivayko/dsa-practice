/*In the city where friends Serhiy and Roman live, the metro consists of a single circular line, along which there are N stations located at equal distances from one another,
numbered from 1 to N. The section of the metro line between two neighboring stations is called a segment. Trains on the circular line move both clockwise and counterclockwise,
so to get from one station to another, a passenger can choose the direction that requires traveling the fewest segments. The minimum number of segments that must be traveled to get
from one station to another is called the distance between the stations. The friends noticed that a certain condition holds: if you choose some station X and write down two numbers for it:
DS – the distance from the station where Serhiy lives to station X and DR – the distance from the station where Roman lives to station X, then the resulting pair of numbers [DS, DR] will uniquely define station X.*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long result = 0;

    for (int d = 1; d <= N / 2; ++d) {
        if (2 * d != N) {
            result += 2 * N;
        }
    }

    cout << result << endl;
    return 0;
}
