//two way to find little span tree
//      1.Kruskal AKA disjion set:
//          choose the two nodes are not connected and with the shortest edge
//      2.Prim:
//          choose the node which is closest to the tree and add it in the tree
#include<iostream>
#include<algorithm>
using namespace std;

// the data structure of disjion set
int djset[100005];

struct Edge{
    int s, t, w;
};

Edge edges[200005];

bool cmp(Edge a, Edge b){
    if(a.w != b.w) return a.w < b.w;
    if(a.s != b.s) return a.s < b.s;
    return a.t < b.t;
}

long long way1(int n, int m){
    sort(edges, edges + m, cmp);
    build(n+5);
    long long  sum = 0;
    for(int i = 0;i<m;i++){
        if(!same(edges[i].s, edges[i].t)){
            combine(edges[i].s, edges[i].t);
            sum += edges[i].w;
        }
    }
    bool flag = false;
    for(int i =1;i<n;i++){
        if(!same(0, i)){
            flag = true;
            break;
        }
    }
    if(flag) return -1;
    return sum;
}

