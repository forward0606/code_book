int nexts[50005]={0};

void getNext(string s, int next[]) {
    int i,j;
    j=0;
    nexts[0]=0;
    for(i=1;i<s.size();i++){
        while(j>0 && s[i] != s[j])
            j = next[j-1];
        if(s[i]==s[j])
            j++;
        nexts[i]=j;
    }
}
// h means the text n means the pattern
int get_pos(string h, string n){
    int j=0;
    for(int i = 0; i < h.size(); i++){
        if(h[i]==n[j]){
            j++;

            if(j == n.size())
                return i-n.size()+1;
        }else{
            while(j > 0 && h[i] != n[j])
                 j = nexts[j-1];
            if(h[i]==n[j])
                j++;
        }

    }

    return -1;
}
