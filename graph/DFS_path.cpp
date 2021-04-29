// O(M+N) untested

vector< vector<int> > graph;
bool vis[MaxSize];
vector<int> path;//path[0] = start

// remember to initial graph vis path
void dfs_path(int x){
    if(x == terminal){
        cout<<path<<endl;
        return;
    }
    if(vis[x]) return;
    vis[x] = true;
    for(int e:graph[x]){
        path.push_back(e);
        dfs(e);
        path.pop_back(e);
    }
}
