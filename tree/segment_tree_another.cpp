#include<iostream>
using namespace std;
#define maxSize 200005

// different segment tree

const int edge_situation = 0;
struct Node{
    int L, R;
    long long val;
}tree[4*maxSize];

int a[maxSize];

void build(int idx, int L, int R){
    tree[idx].L = L;
    tree[idx].R = R;
    if(L == R){
        tree[idx].val = a[L];
        return ;
    }
    int M = (L+R)/2;
    build(idx*2, L, M);
    build(idx*2+1, M+1, R);
}

long long query(int idx, int pos){
    if(tree[idx].L > pos || tree[idx].R < pos){
        return edge_situation;
    }
    if(tree[idx].L == pos && tree[idx].R == pos){
        return tree[idx].val;
    }
    int M = (tree[idx].L+ tree[idx].R)/2;
    if(pos <= M){
        return tree[idx].val + query(idx*2, pos);
    }
    return tree[idx].val + query(idx*2+1, pos);
}

void update(int idx, int uL, int uR, int modify){
    if(tree[idx].R < uL || tree[idx].L > uR){
        return;
    }
    if(tree[idx].L >= uL && tree[idx].R <= uR){
        tree[idx].val += modify;
        return;
    }
    update(idx*2, uL, uR, modify);
    update(idx*2+1, uL, uR, modify);
}

int main(){
     int n, q;
     while(cin>>n>>q){
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            build(1, 0, n);
            int k, x, y, u;
            while(q--){
                cin>>k;
                if(k == 1){
                    cin>>x>>y>>u;
                    update(1, x-1, y-1, u);
                }
                else{
                    cin>>k;
                    cout<<query(1, k-1)<<'\n';
                }
            }
     }
    return 0;
}


/*
question:

https://cses.fi/problemset/task/1651/

Given an array of n integers,
your task is to process q queries of the following types:
    1:increase each value in range [a,b] by u
    2:what is the value at position k?
*/
