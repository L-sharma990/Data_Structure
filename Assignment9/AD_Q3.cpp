#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,e; cin>>n>>k>>e;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int> d(n+1,1e9);
    d[k]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        int u=x.second;
        for(auto &p:g[u]){
            int v=p.first,w=p.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,d[i]);
    cout<<(ans>=1e9?-1:ans);
}
