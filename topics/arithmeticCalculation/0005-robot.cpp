/*The Wall-E robot has taken a new job in a small warehouse that serves the Zamazoe company. The warehouse has long been completely autonomous, so only 1 robot works there. There are only # shelves in the warehouse, which are numbered with integers from 1 to M. All shelves are located on one side of the track along which our robot moves. The shelves are not necessarily arranged in ascending order from the beginning of the track.
The Wall-E robot has two containers: a working one and a procrastination one. Initially, the Wall-E working container contains exactly the number of boxes, each of which must be placed on one of the shelves. Each box has a number written on it, which indicates which shelf it should be placed on. Every day, when the robot starts working and walks past the shelves, it receives boxes into its working container sorted in ascending order of the numbers written on them. The robot can only take the box that is at the top of the working container for processing.
The robot starts the route from the shelf, which is located at the beginning of the path. Stopping at each shelf, the robot looks at the shelf number. Then it either passes by, or puts a certain number of boxes in the procrastination container and if there is a box at the top that needs to be put on this shelf, then it puts it and moves on. Wall- And cannot take boxes from the procrastination container.
For example, if Wall-E approaches shelf 5 and the top box needs to be placed on shelf 2, he either puts boxes 2, 3, and 4 in the procrastination bin and puts box 5 on the shelf, or he moves on to the next shelf. In one day, Wall-E walks along the path K times, so when he reaches the end of it, he turns around and walks in the opposite direction, continuing to place boxes.
The Wall-E software is already outdated and cannot place boxes optimally. Therefore, we ask you to update its software, i.e. calculate the maximum number of boxes that Wall-E can theoretically place in 1 working day.*/

#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    static int P[100000];
    for(int i = 0; i < N; ++i){
        cin >> P[i];
    }

    static int tail[100000];
    int len = 0;

    for(int pass = 1; pass <= K; ++pass){
        if(pass & 1){
            for(int i = 0; i < N; ++i){
                int x = P[i];
                int l = 0, r = len;
                while(l < r){
                    int m = (l + r) >> 1;
                    if(tail[m] < x) l = m + 1;
                    else r = m;
                }
                if(l == len) tail[len++] = x;
                else         tail[l]   = x;
            }
        }
         else {
            for(int i = N-1; i >= 0; --i){
                int x = P[i];
                int l = 0, r = len;
                while(l < r){
                    int m = (l + r) >> 1;
                    if(tail[m] < x) l = m + 1;
                    else  r = m;
                }
                if(l == len) tail[len++] = x;
                else   tail[l]   = x;
            }
        }
    }

    cout << len << "\n";
    return 0;
}
