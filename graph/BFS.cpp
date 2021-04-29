//O(N+M) untested
#include<bits/stdc++.h>

vector< vector<int> > graph;
bool vis[MaxSize];
int distance[MaxSize];
//remember to initial graph vis

void BFS(int s,int t){
    queue<int> q;
    q.push(s);
    int keep;
    while(!q.empty()){
        keep = q.front();q.pop();
        if(vis[keep]){continue;}
        vis[keep] = true;
        for(int e:graph[keep]){
            q.push(e);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m ;i++){

    }
    return 0;
}
