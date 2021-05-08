#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector< vector<int> > adj;
vector<int> dis;
vector<int> parent;
int n;//n nodes

void init(void){
    for(int i = 0;i<=n;i++){
        dis[i] = -1;
        parent[i] = -1;
    }
}

// find diameter use twice BFS
// BFS return farthest node from start point

int BFS(int start){
    queue<int> q;
    init();
    int now = start;
    q.push(start);
    dis[start] = 0;
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int u:adj[now]){
            if(dis[u] == -1){
                dis[u] = dis[now] + 1;
                parent[u] = now;
                q.push(u);
            }
        }
    }
    return now;
}


int main(){
    int a, b;
    cin>>n;
    adj.resize(n+5);
    dis.resize(n+5);
    parent.resize(n+5);
    int m = n;
    while(m-- > 1){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int P = BFS(BFS(1));
    //find diameter
    //cout<<dis[P]<<endl;
    //find center;
    int diameter = dis[P];
    for(int i = 0;i< diameter/2;i++){
        P = parent[P];
    }
    if(diameter %2 && parent[P] < P ){
        P = parent[P];
    }
    cout<<P<<endl;
    return 0;
}
