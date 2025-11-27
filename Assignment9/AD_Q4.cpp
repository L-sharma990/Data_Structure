#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> a;
vector<vector<int>> vis;
int m,n;
void dfs(int i,int j){
    vis[i][j]=1;
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int ni=i+dx[k], nj=j+dy[k];
        if(ni>=0&&nj>=0&&ni<m&&nj<n&&!vis[ni][nj]&&a[ni][nj]=='1')
            dfs(ni,nj);
    }
}
int main(){
    cin>>m>>n;
    a.resize(m,vector<char>(n));
    vis.assign(m,vector<int>(n,0));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    int c=0;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        if(!vis[i][j]&&a[i][j]=='1'){ dfs(i,j); c++; }
    cout<<c;
}
