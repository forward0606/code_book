#include <bits/stdc++.h>
using namespace std;
long long int arr[200005];
long long int dp[200005];
long long int maxnum = 0;
int main ()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    fill(dp, dp+n+1, 1e15);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int index = lower_bound(dp, dp + maxnum+1, arr[i]) - dp;
        dp[index] = min(dp[index], arr[i]);
        if(index > maxnum) maxnum = index;
    }
    cout<<maxnum<<endl;
}


