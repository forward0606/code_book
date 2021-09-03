#include <bits/stdc++.h>
// LeetCode Tutorial
// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
using namespace std;
int nexts[50005]={0};
vector<int>ans;
void getNext(string s) {
    int i,j;
    j=0;
    nexts[0]=0;
    for(i=1;i<s.size();i++){
        while(j>0 && s[i] != s[j])
            j = nexts[j-1];
        if(s[i]==s[j])
            j++;
        nexts[i]=j;
    }
    for(int i = 0; i < s.size(); i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i = 0; i < s.size(); i++)
        cout<<nexts[i]<<" ";
    cout<<endl;
}
// h means the text n means the pattern
int get_pos(string h, string n){
    ans.clear();
    int j=0;
    for(int i = 0; i < h.size(); i++){
        if(h[i]==n[j]){
            j++;

            if(j == n.size()){
               //return i-n.size()+1;
               ans.push_back(i-n.size()+1);
               j=j-1;
               while(j > 0 && h[i] != n[j])
                 j = nexts[j-1];
            }

        }else{
            while(j > 0 && h[i] != n[j])
                 j = nexts[j-1];
            if(h[i]==n[j])
                j++;
        }

    }

    return -1;
}

int main ()
{
    string h="aaaaaaaaaaa"; // THE TEXT
    string n="aa"; // THE PATTERN
    getNext(n);
    get_pos(h,n);
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
