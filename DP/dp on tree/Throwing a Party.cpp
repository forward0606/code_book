//giving a tree a choose the most node value sum that all nodes don't connect

// using DFS: ans = max(dp[0][1], dp[1][1]);
int r[1003];// node value
vector<vector<int>> v;
int dp[2][1003];

void init(int n){
    v.clear();
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;// choose
        dp[1][i] = 0;
    }
}

void dfs(int node){
    dp[0][node] += r[node];// choose node
    for(const int& e:v[node]){
        dfs(e);
        dp[0][node] += dp[1][e];
        dp[1][node] += max(dp[1][e], dp[0][e]);
    }
}

// using BFS: ans = max(dp[0][1], dp[1][1]);
int in[1003], r[1003];
vector<vector<int>> v;
int dp[2][1003];
bool vis[1003];

void init(int n){
    v.clear();
    for(int i=0;i<=n;i++){
        in[i] = 0;
        dp[0][i] = 0;
        dp[1][i] = 0;
        vis[i] = 0;
    }
}

void BFS(int n){
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    int node;
    dp[0][1] = r[1];
    while(!q.empty()){
        node = q.front();
        q.pop();
        vis[node] = true;
        dp[0][node] += r[node];
        for(const int& e:v[node]){
            if(vis[e]){continue;}
            --in[e];
            dp[0][e] += dp[1][node];//choose e
            dp[1][e] += max(dp[1][node], dp[0][node]);
            if(e != 1 and in[e] == 0){
                q.push(e);
            }
        }
    }
}
