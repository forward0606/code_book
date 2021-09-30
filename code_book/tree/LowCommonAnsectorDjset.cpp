// use the concept of union and find to find LCA
// outline algorithm
// O(NlogN)

#define INF 100000008
#define maxSize 200005
#define root 1

vector< vector<int> > adj;
vector<vector<pair<int, int> > > query;
int vis[200005];// structure like disjoinset
int ans[200005];// the ans of the Nth query

void init(int n){
    adj.clear();
    query.clear();
    for(int i=1;i<=n;i++){
        vis[i] = i;
        ans[i] = 0;
    }
    adj.resize(n+5);
    query.resize(n+5);
}

int find_r(int x){
    if(x == vis[x]){return x;}
    return vis[x] = find_r(vis[x]);
}

void DFS(int node, int par){
    for(int u:adj[node]){
        DFS(u, node);
    }
    for(auto e:query[node]){
        if(ans[e.second] == 0 and vis[e.first] != e.first){
            ans[e.second] = find_r(e.first);
        }else if(e.first == node){
            ans[e.second] = node;
        }
    }
    vis[node] = par;
}

void query_input(int q){
    for(int i=0, a, b;i<q;i++){
        cin>>a>>b;
        query[a].push_back({b, i});
        query[b].push_back({a, i});
    }
}

// start with DFS(1, 0);
