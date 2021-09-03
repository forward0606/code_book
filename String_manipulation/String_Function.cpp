#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcd";
    // to upper - 32 ASCII to lower + 32 ASCII
    s.substr(2, 2) // start position (including), from the start position count number.
    s.erase(2,2) // start position (including), from the start position count number.
    s.pop_back(); // delete the last element
    s.size();
    s.empty(); // return 1 if empty
    reverse(s.begin() + 1, s.begin()+2); // s.begin() + i, s.begin()+j;
    // int convert to string
    string num = to_string(5);
    // string convert to int
    int number = stoi("123");

}
