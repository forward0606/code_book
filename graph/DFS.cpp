// O(M+N) untested

vector< vector<int> > graph;
bool vis[MaxSize];

//remember to initial graph vis
void dfs(int x){
    if(vis[x]) return;
    vis[x] = true;
    for(int e:graph[x]){
        dfs(e);
    }
}
