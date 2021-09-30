#include<iostream>
#include<queue>
using namespace std;

vector< vector<pair<int, int>> > adj;
vector<bool> vis;

long long Prim(int n){
    // n: number of nodes
    vis.resize(n+5);
    for(int i =0;i<n;i++){
        vis[i] = false;
    }
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>  pq;
    pq.push({0, 0});
    int wei, node;
    long long sum = 0;
    while(!pq.empty()){
        wei =  pq.top().first;
        node = pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        sum += wei;
        vis[node] = true;
        for(auto e:adj[node]){
            if(!vis[e.first]){
                pq.push({e.second, e.first});
            }
        }
    }
    bool flag = false;
    for(int i =0;i<n;i++){
        if(!vis[i]) {
            flag = true;
        }
    }
    return (flag ? -1:sum);
}

int main(){
    int n,m;
    while(cin>>n>>m){
        adj.clear();
        adj.resize(n+5);
        int s, t, w;
        for(int i=0;i<m;i++){
            cin>>s>>t>>w;
            adj[s].push_back({t,w});
            adj[t].push_back({s,w});
        }
        cout<<Prim(n)<<endl;
    }
    return 0;
}
