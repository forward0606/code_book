/* disjoint set */

int djset[105];

void build(int n){
    for(int i=0;i<=n;i++){
        djset[i]=i;
    }
}
int find(int x){
    if(djset[x]==x){
        return x;
    }
    return djset[x]=find(djset[x]);
}

void combine(int a,int b){
    if(find(a)!=find(b)){
        djset[find(a)]=find(b);
    }
}

bool same(int a,int b){
	return find(a)==find(b);
}
