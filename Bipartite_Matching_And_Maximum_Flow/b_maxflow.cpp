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
    /* ---Update Part-- */
    int rev; /* 新增一個int，紀錄我的反向的邊的index */
             /* 意思就是，我的反向流會在adj[to][rev]的地方 */
    /* ---------------- */
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

                /* ---Update Part---- */
                adj[e.to][e.rev].cap += ret;
                /* 再扣掉自己本身容量的同時，加上與自身反向的流量 */
                /* ------------------ */
                return ret;
            }
        }
    }
    return 0;
}
ll max_flow() {
    ll ret = 0;
    ll tmp = 0;

    /* 當還有剩餘流量 */
    while((tmp = DFS(s, INF)) > 0)  {
        /* DFS 從 s 點開始，而當前流量設成無限，
         * 是因為現在還沒有經過任何一條邊，
         * 走了一條邊之後會取 min，也就是那條邊變成瓶頸 */

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
        //add_edge(b,a,-c);
    }
    s=1, t=n;
    cout<<m-max_flow()<<endl;
}
