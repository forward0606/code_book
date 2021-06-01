//O(N*N*N)
// find the shortest path for each pair
// tested
long long dis[510][510];

void init(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
}

void Floyd(int n){
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
}

