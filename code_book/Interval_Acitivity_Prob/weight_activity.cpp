typedef long long int lld;
lld n;
struct acti{
    lld s,t,w; // start, terminal, weight
} act[200005];
bool cmp(acti a, acti b){
    if(a.t == b.t)
        return a.s < b.s;
    return a.t < b.t;
}
lld dp[200005];
lld rec[200005];
lld bs(lld l, lld r, lld select_start);
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>act[i].s>>act[i].t>>act[i].w;
    sort(act+1, act+n+1, cmp);
    act[0].s = act[0].t = act[0].w = 0;
    rec[0]=dp[0]=0;
    for(int i = 1; i <= n; i++){
        lld index=bs(-1, i-1, act[i].s);
        while(index > 0 && rec[index] >= act[i].s)
            index--;
        if(dp[i-1] > dp[index] + act[i].w){
            dp[i] = dp[i-1];
            rec[i] = rec[i-1];
        }else{
            dp[i] = dp[index] + act[i].w;
            rec[i] = act[i].t;
        }
    }
    cout<<dp[n]<<endl;
}

lld bs(lld l, lld r, lld select_start){
    lld mid;
    while(l < r-1)
    {
        mid = (l+r)/2;
        if(rec[mid] >= select_start)
            r = mid;
        else
            l = mid;
    }
    return r;
}
