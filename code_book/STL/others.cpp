#include<algorithm>// fill, sort, __gcd
#include <cstring> // memset

//fill
vector<int> v(5);
fill(v.begin(), v.end(), -1);
fill(a, a+n, 0);

//memset
void* memset( void* dest, int ch, std::size_t count );
int a[20];
std::memset(a, 0, sizeof a);

// sort

bool cmp(int a, int b){
    // should not put '=' in return, '=' will causing RE
    if(a %2 != b % 2){
        return a % 2 > b % 2;
    }
    return a > b;
}
sort(a, a+n, cmp);
lower_bound(a, a+n, x);// first element y >= x
upper_bound(a, a+n, x);// first element y > x
