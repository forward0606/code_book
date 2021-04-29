//O(N+M) untested
#include<bits/stdc++.h>
using namespace std;
#define MaxSize 2010

vector< vector<int> > adj;
int dis[MaxSize];
//remember to initial graph vis

int BFS(int s,int t){
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    int keep;
    while(!q.empty()){
        keep = q.front();q.pop();
        for(int u:adj[keep]){
            if(dis[u] != -1) continue;
            dis[u] = dis[keep] + 1;
            q.push(u);
        }
    }
    return dis[t];
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+5);
    int a,b;
    for(int i = 0;i<m ;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0;i<=n;i++){
        dis[i] = -1;
    }
    cin>>a>>b;
    cout<<BFS(a, b)<<endl;
    return 0;
}
