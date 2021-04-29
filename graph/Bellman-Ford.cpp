#include <tuple>
tuple<int, int, int>   edge[10005];
long long dis[1003];

void bellman_Ford(){
    for(int i=0;i<=n;i++)
        dis[i] = INF;
    dis[1] = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            tie(a, b, w) = edge[j];
            dis[b] = min(dis[b], dis[a]+w);
        }
    }
    // do one more times to found negative cycles
    // negative cycles might not connect to start
}

