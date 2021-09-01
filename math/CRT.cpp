#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
lld inv(lld a, lld m); // a mod m
lld n;
lld T[5], d[5];
lld crt();

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>T[i]>>d[i];

    }

    cout<<crt()<<endl;

}
lld inv(lld a, lld m) // a mod m
{
    lld m0 = m, t, q;
    lld x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}
lld crt()
{
    lld sum=1;
    for(int i = 0; i < n; i++){
        sum *= T[i];
    }
    lld x=0;
    for(int i = 0; i < n; i++){
        x += (d[i]%sum) * inv(sum/T[i], T[i])%sum * (sum/T[i])%sum;
        x %= sum;
    }
    x = x % sum;
    return x ;
}
