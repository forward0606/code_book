//O(N + MlogM)
//N: number of nodes
//M: number of edges
typedef pair<long long, int> plli;
#define INF 0x3f3f3f3f3f3f3f3f

vector< vector<pair<int, int> >> adj;
int path[100005];
long long dis[100005];

void dijkstra(int n, int start){
    for(int i=0; i<=n;i++){
        dis[i] = INF;
    }
    priority_queue<plli, vector<plli>, greater<plli> > pq;
    pq.push({0, start});
    long long distance, w;
    int node, b;
    while(!pq.empty()){
        node = pq.top().second;
        distance = pq.top().first;
        pq.pop();
        if(dis[node] != INF){continue;}
        dis[node] = distance;
        for(auto u:adj[node]){
            b = u.first, w = u.second;
            if(dis[b] > dis[node] + w){
                dis[b] = dis[node] + w;
                pq.push(b, dis[node] + w);
            }
        }
    }
}
