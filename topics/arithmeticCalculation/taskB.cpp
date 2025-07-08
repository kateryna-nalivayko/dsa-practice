#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    vector<vector<int>> row(n,vector<int>(m+1)), col(n+1,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            row[i][j+1]=row[i][j]+(g[i][j]=='#');
        }
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            col[i+1][j]=col[i][j]+(g[i][j]=='#');
        }
    }
    int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
    array<vector<int>,4> perp={
        vector<int>{1,3},
        vector<int>{2,0},
        vector<int>{1,3},
        vector<int>{0,2}
    };
    vector<vector<array<int,4>>> dist(n,vector<array<int,4>>(m,{-1,-1,-1,-1}));
    queue<tuple<int,int,int>> q;
    if(k<=m){
        bool ok=1;
        for(int j=0;j<k;j++) if(g[0][j]=='#'){ok=0;break;}
        if(ok){
            dist[0][k-1][0]=0;
            q.emplace(0,k-1,0);
        }
    }
    if(k<=n){
        bool ok=1;
        for(int i=0;i<k;i++) if(g[i][0]=='#'){ok=0;break;}
        if(ok){
            dist[k-1][0][1]=0;
            q.emplace(k-1,0,1);
        }
    }
    int ti=n-1,tj=m-1,ans=-1;
    while(!q.empty()){
        auto [i,j,d]=q.front();q.pop();
        int c=dist[i][j][d];
        if(i==ti&&j==tj){ans=c;break;}
        int ni=i+dx[d],nj=j+dy[d];
        if(ni>=0&&ni<n&&nj>=0&&nj<m&&g[ni][nj]=='.'&&dist[ni][nj][d]==-1){
            dist[ni][nj][d]=c+1;
            q.emplace(ni,nj,d);
        }
        ni=i-dx[d],nj=j-dy[d];
        int ti2=ni-(k-1)*dx[d],tj2=nj-(k-1)*dy[d];
        if(ni>=0&&ni<n&&nj>=0&&nj<m&&ti2>=0&&ti2<n&&tj2>=0&&tj2<m){
            if(g[ni][nj]=='.'&&g[ti2][tj2]=='.'&&dist[ni][nj][d]==-1){
                dist[ni][nj][d]=c+1;
                q.emplace(ni,nj,d);
            }
        }
        for(int nd:perp[d]){
            ti2=i+(k-1)*dx[nd];
            tj2=j+(k-1)*dy[nd];
            if(ti2<0||ti2>=n||tj2<0||tj2>=m) continue;
            bool ok=1;
            if(dx[nd]==0){
                int c1=j,c2=tj2;
                if(c1>c2) swap(c1,c2);
                if(row[i][c2+1]-row[i][c1]>0) ok=0;
            } else {
                int r1=i,r2=ti2;
                if(r1>r2) swap(r1,r2);
                if(col[r2+1][j]-col[r1][j]>0) ok=0;
            }
            if(ok&&dist[ti2][tj2][nd]==-1){
                dist[ti2][tj2][nd]=c+1;
                q.emplace(ti2,tj2,nd);
            }
        }
    }
    cout<<ans;
    return 0;
}
