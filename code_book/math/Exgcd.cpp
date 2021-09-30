//O(logN)
//find ax + by = gcd(a, b); use in find inverse in modular

//two way to find s*t %m = 1
//      1.if m is a prime and gcd(s, m) == 1 --> Fermat’s Little Theorem
//              If p is prime and a is an integer not divisible by p, then a^(p-1)%p = 1
//              find a^(p-2) with fast exponotial
<<<<<<< HEAD
//      2.if gcd(s, m) == 1 -->Bezout�s Theorem
=======
//      2.if gcd(s, m) == 1 -->Bezout’s Theorem
>>>>>>> a09791fe2f6f9a9dc666dc0f749beae5d65b5098
//              If a and b are positive integers,
//              then there exist integers s and t such that gcd(a,b) = sa + tb.
//              make a = s, b = m, then t = x;


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
