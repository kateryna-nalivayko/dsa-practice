/*In the elective class, sessions are held weekly on the same day of the week, starting from a certain date. Write a program that, 
given the month and day of the first class, outputs all the dates of the classes until the end of the year inclusive.*/

#include <iostream>
using namespace std;

int main() {
    int m, d;
    cin >> m >> d;

    int daysInMonth[13] = {
        0, 
        31, 
        28,
        31,
        30, 
        31, 
        30, 
        31, 
        31, 
        30, 
        31, 
        30, 
        31  
    };
    
    int curM = m, curD = d;
    while (curM <= 12) {
        cout << curM << " " << curD << "\n";
        curD += 7;
        
        while (curM <= 12 && curD > daysInMonth[curM]) {
            curD -= daysInMonth[curM];
            curM++;
        }
    }
    
    return 0;
}
