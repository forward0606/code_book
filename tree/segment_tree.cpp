#include<iostream>
using namespace std;
#define MaxSize 200005
#define EdgeStatuation 1000000009

int a[MaxSize];

struct Node{
    int left, right;
    int val;
}tree[4*MaxSize];

int pull(int x, int y){
    //think of divide and conquer
    return min(x, y);
}
// root : idx = 1
void build(int idx, int L, int R){
    tree[idx].left = L;
    tree[idx].right = R;
    if(L == R){
        tree[idx].val = a[L];
        return;
    }
    int M = (L + R)/2;
    build(idx*2, L, M);
    build(idx*2+1, M+1, R);
    tree[idx].val = pull(tree[idx*2].val, tree[idx*2+1].val);
}

int query(int idx, int qL, int qR){
    if(tree[idx].right < qL || tree[idx].left > qR){
        return EdgeStatuation;
    }
    if(tree[idx].left >= qL && tree[idx].right <= qR){
        return tree[idx].val;
    }
    return pull(query(idx*2, qL, qR), query(idx*2+1, qL, qR));
}

void update(int idx, int pos, int modify){
    if(tree[idx].right < pos || tree[idx].left > pos){
        return;
    }
    if(tree[idx].right == pos && tree[idx].left == pos){
        tree[idx].val = modify;
        return;
    }
    update(idx*2, pos, modify);
    update(idx*2+1, pos, modify);
    tree[idx].val = pull(tree[idx*2].val, tree[idx*2+1].val);
}
