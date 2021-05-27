#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<long long, int> plli;
#define INF 0x3f3f3f3f3f3f3f3f

vector< vector<pair<int, int> >> adj;
bool vis[100005];
int path[100005];
long long dis[100005];


int main(){
    int n, m;
    cin>>n>>m;
    adj.resize(n+5);
    int s, t, w;
    for(int i=0; i<m; i++){
        cin>>s>>t>>w;
        adj[s].push_back({t, w});
        adj[t].push_back({s, w});
    }
    for(int i=0;i<=n;i++){
        vis[i] = false;
        dis[i] = INF;
    }
    priority_queue<plli, vector<plli>, greater<plli> > pq;
    pq.push({0, 1});
    dis[1] = 0;
    path[1] = -1;
    long long distance;
    int node;
    while(!pq.empty()){
        node = pq.top().second;
        distance = pq.top().first;
        pq.pop();
        if(vis[node] == true) continue;
        vis[node] = true;
        for(auto u:adj[node]){
            if(dis[u.first] > distance + u.second){
                dis[u.first] = distance + u.second;
                path[u.first] = node;
                pq.push({dis[u.first], u.first});
            }
        }
    }
    if(dis[n] == INF){
        cout<<-1<<'\n';
        return 0;
    }
    vector<int> pth;
    int x = n;
    while(x != -1){
        pth.push_back(x);
        x = path[x];
    }
    for(int i = pth.size()-1;i>=0;i--){
        cout<<pth[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
