/*The railway of Potokolyandia is a straight line along which there are n stations. We will call the section of the railway from one station to the next a segment. 
The train travels from station 1 to station n, stopping at each station. There are k seats on the train, numbered from 1 to k. Tickets are sold for the train, each ticket is characterized by three numbers:
s, t, and a. Such a ticket allows travel from station s to station t in seat a. Stepan plans to travel by train from one station to another on one of the days of his summer holidays. He discovered that m tickets
have already been sold for the train on that day, and it may be that there are no free seats available on all segments between the stations he is interested in. A ticket from one station to another for a specific seat 
can only be purchased if that seat is free on all segments between those stations. Stepan realized that sometimes it is still possible to travel from one station to another by purchasing several tickets and changing from one seat to another 
at some intermediate stations.It is clear that switching from seat to seat is inconvenient, so Stepan wants to buy the minimum number of tickets so that he has his own seat on each leg of the journey. Stepan has not yet decided from which station he will travel and to which one. 
He has noted down q travel options, and for each of them, he wants to find out the minimum number of tickets he will have to buy if he chooses that option. A program needs to be written that, based on the given description of already sold tickets and Stepan's travel options, determines the 
minimum number of tickets that need to be purchased for each option to make such a journey.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> sold(k+1);
    for(int i = 0; i < m; ++i){
        int s, t, a;
        cin >> s >> t >> a;
        sold[a].emplace_back(s, t);
    }

    int q;
    cin >> q;
    vector<pair<int,int>> qs(q);
    for(int i = 0; i < q; ++i){
        cin >> qs[i].first >> qs[i].second;
    }

    int segN = n - 1;
    vector<int> maxReachStart(segN + 2, 0);

    for(int a = 1; a <= k; ++a){
        auto &v = sold[a];
        if(v.empty()){
            if(segN >= 1)
                maxReachStart[1] = max(maxReachStart[1], segN);
        } else {
            sort(v.begin(), v.end());
            int prev = 1;
            for(auto &p : v){
                int s = p.first, t = p.second;
                int l = prev, r = s - 1;
                if(l <= r)
                    maxReachStart[l] = max(maxReachStart[l], r);
                prev = t;
            }
            int l = prev, r = segN;
            if(l <= r)
                maxReachStart[l] = max(maxReachStart[l], r);
        }
    }

    vector<int> maxRupto(segN + 2, 0);
    int curMax = 0;
    for(int i = 1; i <= segN; ++i){
        curMax = max(curMax, maxReachStart[i]);
        maxRupto[i] = curMax;
    }

    int LOG = 0;
    while((1 << LOG) <= n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n + 2));

    for(int i = 1; i <= n; ++i){
        if(i <= segN && maxRupto[i] >= i)
            up[0][i] = maxRupto[i] + 1;
        else
            up[0][i] = i;
    }

    for(int j = 1; j < LOG; ++j){
        for(int i = 1; i <= n; ++i){
            up[j][i] = up[j-1][ up[j-1][i] ];
        }
    }

    for(int i = 0; i < q; ++i){
        int f = qs[i].first, d = qs[i].second;
        if(f >= d){
            cout << 0 << "\n";
            continue;
        }
        if(up[0][f] == f){
            cout << -1 << "\n";
            continue;
        }
        int ans = 0, cur = f;
        for(int j = LOG - 1; j >= 0; --j){
            if(up[j][cur] < d){
                ans += 1 << j;
                cur = up[j][cur];
            }
        }
        if(up[0][cur] < d)
            cout << -1 << "\n";
        else
            cout << ans + 1 << "\n";
    }

    return 0;
}
