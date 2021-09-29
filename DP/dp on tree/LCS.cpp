#include <bits/stdc++.h>
using namespace std;
int dp[1002][1002] = {0};
int t;
string s1, s2; // string 1, string 2
int main ()
{
    cin>>t;
    getline(cin, s1);
    getline(cin, s2);
    int l1 = s1.length(), l2 = s2.length();
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[l1][l2]<<endl;
}
