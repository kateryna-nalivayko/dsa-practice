/*Lady has a birthday (which we congratulate her on!), which she decided to celebrate with her friends in the dormitory. To celebrate, she bought a mountain of products, including her favorite sausage loaf.
There was so much food that the birthday girl's favorite loaf was only remembered after more than two hours. And, of course, in honor of such a significant date, her friends decided to eat this loaf as soon as possible.
But on this path, they faced one difficulty: the loaf must be cut into N (according to the number of friends) equal parts, and as quickly as possible so as not to miss the moment. For this purpose, a very long and sharp knife was found, which, 
if necessary, could cut even N sausage loaves at once. In addition, a ruler was found, with the help of which you can measure any predetermined part of the loaf, choosing the place of the future cut with sufficient accuracy. The sausage loaf turned out to be so thin and long
(student life is not easy) that it made sense to cut it only perpendicular to its axis.
Of course, the friends quickly realized that to speed up the process, you can cut several
pieces of the loaf at the same time. The sausage loaf turned out to be straight and inflexible, so saving
the number of actions by folding the loaf before cutting is impossible. They just have to determine the
minimum number of movements with the knife, with which they can carry out their intentions. Help
them with this.
In the process of cutting, the Lady can put some of the pieces of the sausage loaf she has one
to each other as she wants (recall that the loaf is very long and thin, so it makes sense to put the
pieces only parallel to each other), and cut all the pieces with one movement of the knife. Initially, the Lady has one piece - the loaf itself; at the end she should have N pieces of the same length.
For example: to cut a loaf into 6 pieces (N = 6) Lady can do it in just 3 actions with a knife:
1. Measure 1/3 of the length of the entire loaf and cut the loaf at this point.
2. Cut the larger piece in half (resulting in three pieces of equal length).
3. Putting them close to each other, align the ends and cut all three pieces
in the middle, resulting in six identical pieces.
To cut a loaf into 5 equal pieces (N = 5), 3 actions with a knife are also required, for example:
1. Measure 2/5 of the length of the loaf and cut the loaf at this point.
2. We put the formed pieces together so that the middle of the smaller piece is
against a third of the larger one, and we cut them so that the smaller one is cut in half, and the larger one - in a
ratio of 1 : 2. We get three pieces 1/5 of the length of the entire loaf and one -
2/5 of the length.
3. We cut the larger of the available pieces in half and we get five identical pieces*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    int cuts = 0;
    long long power = 1;
    while (power < N) {
        power <<= 1;
        cuts++;
    }

    cout << cuts << "\n";
    return 0;
}
