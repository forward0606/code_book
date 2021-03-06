typedef long long int lld;
struct bag
{
    int w, v;// weight and value.
}o[1005]; // object
lld dp[1005][100005] = {0};
set<int> use;
set<int>  ::  iterator it1, it2;
cin>>n>>m; // n object and m weigt
for(int i = 0; i < n; i++)
    cin>>o[i].v>>o[i].w; 
// initialize
for(int i = 1; i <= n; i++)
    for(int j = 0; j <= m; j++)
        if(o[i-1].w <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-o[i-1].w] + o[i-1].v);
        else 
            dp[i][j] = dp[i-1][j];
        
int rec_pos = m;
lld tmp = dp[n][rec_pos];
// the i means the line from down to top and means the object which is used if not continue.
// the below we can draw a DAG to debug
for(int i = n; i >= 0; i--){
    if(tmp == dp[i][rec_pos]) continue;
    rec_pos -= o[i].w;
    tmp = dp[i][rec_pos];
    use.insert(i);
}
it1 = use.begin();
it2 = use.end();
cout<<use.size()<<endl;
while(it1!=it2)
{
    cout<<*it1<<" ";
    it1++;
}
