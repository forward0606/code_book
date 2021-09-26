// build O(N), inverse O(log(MOD))

long long factorial[1000006];
const long long MOD = (1e9)+7;// should be a prime

void build(){
    factorial[0] = 1;
    for(int i=1;i<=1000000;i++){
        factorial[i] = factorial[i-1]*i % MOD;
    }
}

long long inverse(long long x){
    return exp(x, MOD-2);
}

long long binomial_coefficients(int n, int m){
    return factorial[n] * inverse(factorial[m])%MOD * inverse(factorial[n-m])%MOD;
}
