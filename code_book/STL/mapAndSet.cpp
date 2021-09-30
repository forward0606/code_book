#include<map> // header file of map
#include<set> // header file of set

// 宣告
map<int, int> mp;
set<int> s;
//自訂型態: key要有operator <

// usage

// add thing in it
    mp[x] = y;
    s.insert(x);
// access thing
    y = mp[x];
// check x exist or not
    mp.find(x) != mp.end();
    s.find(x) != s.end();
// check empty
    mp.empty();
    s.empty();
// check size
    mp.size();
    s.size();
// binary search
    map<int, int>::iterator it = mp.lower_bound(x);
    set<int>::iterator it2 = s.lower_bound(x);
    if(it == mp.end()){}//not found
    *it// the first element y >= x
    // upper_bound: first element y > x
