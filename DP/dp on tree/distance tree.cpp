// find the sum of all path cost
// O(N)
void init(){
    v.clear();
    ans = 0;
    for(int i=0;i<=n;i++){
        si[i] = 0;
    }
}

void dfs(int node){
    if(si[node] !=0){return;}
    si[node] += 1;
    for(const int& e:v[node]){
        dfs(e);
        ans += weight[e] * (n-si[e]) * (si[e]) * 2;
        si[node] += si[e];
    }
}
