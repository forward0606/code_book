// statics range sum query
// preprocess O(N), find range sum O(1)
long long int sum[200005];

void prefix_sum(int n){
    sum[0] = 0;
    for(int i=1;i<=n;i++){
		sum[i] += sum[i-1];
	}
}

long long get_sum(int l, int r){
    return sum[r]-sum[l-1];
}
