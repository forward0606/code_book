string pattern, text;

int first_place_matching = -1;
int next[200006];
int main ()
{
    getline(cin, pattern);
    getline(cin, text);
    int l = pattern.length(), n = text.length();
    int j = 0;
    next[0] = 0;
    // building prefix_substring_array
    for(int i = 1; i < l; i++){
        if(pattern[i] == pattern[j]){
            next[i] = (j+1);
            j += 1;
            continue;
        }
        // they didn't match in this round.
        while(pattern[j] != pattern[i] && j != 0)
            j = next[j-1];
        if(pattern[i] == pattern[j]){
            next[i] = (j+1);
            j += 1;
        }
        else{
            next[i] = 0;
        }
    }
    /*for(int i = 0; i < l; i++)
        cout<<next[i]<<" ";
    cout<<endl;*/

    // j is the pointer for pattern. i is the pointer of the text.
    int i;
    for(i=0, j=0; i < n; i++){
        if(pattern[j] == text[i]){
            j++;
            if(j == l) break;
            continue;
        }
        while(pattern[j] != text[i] && j != 0)
            j = next[j];

        if(pattern[j] == text[i]) j++;
    }
    //cout<<"i "<<i <<" j "<<j<<endl;

    // we +1 beacause the array counts from 0
    if(j == l) cout<<i-l+1<<" is the first_place_matching"<<endl;

}
