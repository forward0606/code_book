#include<bits/stdc++.h>
using namespace std;

long long exp(long long base, long long deg, long long mod){
    base = base % mod;
    long long sum = 1;
    while(deg > 0){
        if(deg & 1){
            sum = (sum * base) % mod;
        }
        base = (base * base) % mod;
        deg >>= 1;
    }
    return sum;
}

struct Complix{
    long long r, v, w, p;
    Complix(long long _r, long long _v, long long _w, long long _p):r(_r), v(_v), w(_w), p(_p){};
    Complix operator*(const Complix& right){
        long long _r = r * right.r % p + v * right.v % p * w % p;
        long long _v = v * right.r % p + r * right.v % p;
        _r %= p, _v %= p;
        return Complix(_r, _v, w, p);
    }
};


long long inverse(long long x, long long mod){
    return exp(x, mod-2, mod);
}

long long exp(Complix base, long long deg){
    Complix sum = Complix(1, 0, base.w, base.p);
    while(deg > 0){
        if(deg & 1){
            sum = (sum * base);
        }
        base = (base * base);
        deg >>= 1;
    }
    return sum.r;
}

int main(){
    srand(time(NULL));
    int T;
    cin>>T;
    long long a, b, d, p;
    while(T--){
        cin>>a>>b>>d>>p;
        if(d == 0){
            cout<<(p-b)%p<<'\n';
            continue;
        }
        if(p == 2){
            //a == 1
            cout<< ((b+d) & 1)<<'\n';
            continue;
        }
        d = d * inverse(a, p) % p;
        if(exp(d, (p-1)/2, p) == p-1 || exp(d, (p-1)/2, p) == -1){
            cout<<-1<<'\n';
            continue;
        }
        long long _a, _w;
        bool flag = false;
        while(!flag){
            _a = (rand() % p + p) % p;
            _w = (_a*_a - d) % p;
            if(  or exp(_w, p/2, p) == -1){
                flag = true;
            }
        }
        Complix c = Complix(_a, 1, _w, p);
        long long solution = exp(c, (p+1)/2);
        long long ans1 = ((solution - b)%p + p) % p;
        long long ans2 = ((-solution - b)%p + p) % p;
        if(ans1 == ans2){cout<<ans1<<endl;continue;}
        cout<<min(ans1, ans2)<<" "<<max(ans1, ans2)<<endl;
    }
    return 0;
}
