// O(M+N) untested

vector< vector<int> > adj;
bool vis[MaxSize];
vector<int> path;//path[0] = start

// remember to initial adj vis path
void dfs_path(int x){
    if(x == terminal){
        cout<<path<<endl;
        return;
    }
    if(vis[x]) return;
    vis[x] = true;
    for(int e:adj[x]){
        path.push_back(e);
        dfs(e);
        path.pop_back(e);
    }
}
