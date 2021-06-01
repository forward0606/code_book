//O(logN)
//find ax + by = gcd(a, b); use in find inverse in modular
int ex_gcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long d = ex_gcd(b, a%b, x, y);
    long long temp = y;
    y = x - y*(a/b);
    x = temp;
    return d;
}
