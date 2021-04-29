// O(M+N) untested

vector< vector<int> > adj;
bool vis[MaxSize];

//remember to initial adj vis
void dfs(int x){
    vis[x] = true;
    for(int e:adj[x]){
        if(!vis[e]) dfs(e);
    }
}
