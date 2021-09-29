#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int> act[200005];
bool cmp (pair<int, int> a, pair<int, int> b){
    if(a.second == b. second)
        return a.first < b.first;
    return a.second < b.second;

}
int main ()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>act[i].first>>act[i].second;
    sort(act, act+n, cmp);

    int e=1;
    int cnt=0;
    for(int i = 0; i < n; i++){
        if(act[i].first >= e){
            e = act[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
