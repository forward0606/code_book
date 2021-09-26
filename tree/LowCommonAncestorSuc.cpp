// use successor graph's data structure to find LCA
// O(NlogN)

vector<vector<int>> v;
int suc[32][200005];
int deep[200005];

void dfs(int node, int par){
    suc[0][node] = node;
    suc[1][node] = par;
    deep[node] = deep[par]+1;
    for(int u:v[node]){
        if(u != par){
            dfs(u, node);
        }
    }
}

void build(int n){
    for(int i = 2; i<32;i++){
        for(int j = 1;j<=n;j++){
            suc[i][j] = suc[i-1][suc[i-1][j]];
        }
    }
}

int jump(int node, int k){
    int i = 1;
    while(k > 0){
        if(k & 1){
            node = suc[i][node];
        }
        k = k>>1, i++;
    }
    return node;
}

int find_LCA(int node1, int node2){
    if(deep[node1] < deep[node2]){
        swap(node1, node2);
    }
    node1 = jump(node1, deep[node1] - deep[node2]);
    for(int i = 31;i>0;i--){
        if(suc[i][node1] != suc[i][node2]){
            node1 = suc[i][node1];
            node2 = suc[i][node2];
        }
    }
    if(node1 != node2){
            node1 = suc[1][node1];
    }
    return node1;
}

int find_distance(int node1, int node2){
    int lca = find_LCA(node1, node2);
    return deep[node1] + deep[node2] - 2*deep[lca];
}

