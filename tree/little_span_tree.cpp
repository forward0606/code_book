//two way to find little span tree
//      1.disjion set:
//          choose the two nodes are not connected and with the shortest edge
//      2.Prim:
//          choose the node which is closest to the tree and add it in the tree

int way1(){
    sort(edge.begin(), edge.end());
    int sum = 0;
    for(auto e:edge){
        if(!same(e.start, e.terminal)){
            combine(e.start, e.terminal);
            sum += e.weight;
        }
    }
    return sum;
}

int Prim(){
    priority_queue<plli, vector<plli>, greater<plli> > pq;
    pq.push({0, start});
    while(!pq.empty()){
        node = pq.second;
        if(vis[node]){continue;}
        sum += pq.first;
        for(auto u:adj[node]){
            if(!vis[u]){
                pq.push({);
            }
        }
    }
}
