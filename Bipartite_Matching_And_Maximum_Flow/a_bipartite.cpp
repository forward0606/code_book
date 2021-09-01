#include<bits/stdc++.h>
using namespace std;
# define N 5000 // N has to be larger than n+m
int n, m, k; // n = left set size, m = right set ,¡÷size, k = number of edge
int match[N]; bool used[N]; vector<int> adj[N];
bool DFS(int x) {
    for(auto u : adj[x]) {
        if(used[u]) continue;
        used[u] = 1;
        int next = match[u];
        if(next == -1 || DFS(next)) {
            match[u] = x;
            return 1;
        }
    }
    return 0;
}

int Bipartite_match() {
    memset(match, -1, sizeof(match));
    int match_number = 0;
    for(int i = 1;i <= n;i++) {
        memset(used, 0, sizeof(used));

        match_number += DFS(i);
        //cout<<match_number<<endl;
    }
// and if(match[i] != -1) {i(right set) and ,¡÷match[i](left set) match}
    return match_number;
}
void init() {
    for(int i = 0;i < k;i++) {
        int a, b; scanf("%d%d", &a, &b);
        b = b + n;
        adj[a].push_back(b); // a in left set, b ,¡÷in right set
    }
}
