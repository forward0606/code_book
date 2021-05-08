#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector< vector<int> > adj;
int edgecnt[200005];
int dis[200005];

int tree_diameter(int n){
    //found the longest
    //shortest path from two points on tree
    if(n == 1) {
        // only the one node
        //diameter = 0
        return 0;
    }
    for(int i = 0;i<=n;i++){
        //initial
        dis[i] = -1;
    }
    queue<int> q;
    for(int i =1;i<=n; i++){
        edgecnt[i] = adj[i].size();
        if(edgecnt[i] == 1){
            // find leaves
            dis[i] = 0;
            q.push(i);
        }
    }
    int last = 1;
    bool flag = false;
    while(!q.empty()){
        last = q.front();
        q.pop();
        for(int u:adj[last]){
            //remove the node for every node
            //connected to the remove node
            edgecnt[u] -= 1;
            if(edgecnt[u] == 1){
                dis[u] = dis[last] +1;
                q.push(u);
            }
        }
    }
    //inspect the node connected to last
    //for same dis[] (case : O-O)
    for(int u:adj[last]){
        if(dis[u] == dis[last]){
            flag = true;
            break;
        }
    }
    if(flag) return 2 *dis[last] +1;
    return 2*dis[last];
}

int main(){
    int n;
    int a, b;
    cin>>n;
    adj.resize(n+5);
    int m = n;
    while(m-- > 1){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<tree_diameter(n)<<endl;
    return 0;
}
