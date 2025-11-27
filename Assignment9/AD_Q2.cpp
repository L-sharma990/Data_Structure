#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n; cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    vector<vector<int>> d(m,vector<int>(n,1e9));
    d[0][0]=a[0][0];
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    pq.push({a[0][0],0,0});
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        int w=x[0],i=x[1],j=x[2];
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0&&nj>=0&&ni<m&&nj<n&&d[ni][nj]>d[i][j]+a[ni][nj]){
                d[ni][nj]=d[i][j]+a[ni][nj];
                pq.push({d[ni][nj],ni,nj});
            }
        }
    }
    cout<<d[m-1][n-1]-a[0][0]+a[m-1][n-1];
}
