// find the deepest subtree's root
// which contains two node
// the distance of two node = deep[a] + deep[b] - 2*deep[c]
// two way to solve the problem
// O(height)
#define maxSize 30004
#define root 1
int deep[maxSize];
int parentid[maxSize];
vector< vector<int> > adj;

void init_aka_DFS(int node){
    // before call it make root's deep = 1
    // and call DFS(root)
    for(int u:adj[node]){
        deep[u] = deep[node]+1;
        parentid[u] = node;
        DFS(u);
    }
}

int way1(int a, int b){
    while(deep[a] > deep[b]){
        a = parentid[a];
    }
    while(deep[a] < deep[b]){
        b = parentid[b];
    }
    while(a != b){
        a = parentid[a];
        b = parentid[b];
    }
    return a;
}
