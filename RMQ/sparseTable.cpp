// statics range gcd/min query
// preprocess O(NlongN), find range sum O(logN)
long long a[200005];
long long sparse[25][200005];

void build(int n){
    for(int i=0;i<n;i++){
        sparse[0][i] = a[i];
    }
    for(int i=1;(1<<i) <n;i++){
        for(int j=0;j+(1<<i) <n;j++){
            sparse[i][j] = __gcd(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
        }
    }
}

long long query(int left, int right){
    int g = right - left +1, cnt = 0;
    while((1<<cnt) <= g){
        ++cnt;
    }
    --cnt;
    return __gcd(sparse[cnt][left], sparse[cnt][right-(1<<cnt)+1]);
}
