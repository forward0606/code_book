// Miller-Rabin
// https://www.cnblogs.com/RioTian/p/13927952.html
// O(K*logN) k is modifiable just consider the correctness
// use random algorithm to check a number is prime or not

long long exp(__int128 base, long long deg, long long mod){
    __int128 sum = 1;// use __int128 or fast_multipy to avoid overflow
    while(deg > 0){
        if(deg & 1){
            sum = sum * base % mod;
        }
        base = base * base % mod;
        deg /= 2;
    }
    return sum;
}

bool is_prime(long long n){
    if(n == 2){return true;}
    if(n == 1 or n %2 == 0){return false;}
    long long s=0, d=n-1;
    while((d & 1) == 0){
        s++, d/=2;
    }
    int k = 100;
    long long a;
    while(k--){
        a = rand() % n;
        if(a == 0){continue;}
        bool flag = false;
        if(exp(a, d, n) == 1){flag = true;}
        for(int i=0;i<s;i++){
            if(exp(a, (1LL<<i)*d, n) == n-1){
                flag = true;
            }
        }
        if(!flag){return false;}
    }
    return true;
}
