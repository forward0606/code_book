#include<bits/stdc++.h>
using namespace std;
#define N 5050
#define INF 1e18
typedef long long ll;
int n,m,a,b,c;
int vis[5050]={0};
struct Edge {
    int to;
    ll cap;
    int rev; /* 新增一個int，紀錄我的反向的邊的index */
    //Edge(){} /*記得改一下 constructor */
    Edge(int _to, ll _cap, int _rev): to(_to), cap(_cap), rev(_rev) {}
};

vector<Edge> adj[N];

void add_edge(int from, int to, ll cap) {
    adj[from].push_back(Edge(to, cap, (int)adj[to].size()));
    /* from -> to, e.cap = cap */

    adj[to].push_back(Edge(from, 0, (int)adj[from].size() - 1));
    /* to -> from, e.cap = 0 */
}


int s, t;
ll DFS(int now, ll flow) {
    if(now == t) return flow;
    vis[now] = 1;
    for(int i = 0;i < (int)adj[now].size();i++) {
        Edge &e = adj[now][i];
        if(e.cap > 0 && !vis[e.to]) {
            ll ret = DFS(e.to, min(flow, e.cap));
            if(ret > 0) {
                e.cap -= ret;
                adj[e.to][e.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}
ll max_flow() {
    ll ret = 0;
    ll tmp = 0;
    while((tmp = DFS(s, INF)) > 0)  {
        ret += tmp;
        memset(vis, 0, sizeof(vis)); /* 初始化 */
    }
    return ret;
}
int main ()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;

        add_edge(a,b,c);
        add_edge(b,a,-c);
    }
    s=1, t=n;
    cout<<max_flow()<<endl;
}
