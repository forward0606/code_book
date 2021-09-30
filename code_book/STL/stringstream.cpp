#include<sstream>// header file of stringstream

stringstream ss;

void init(){// initialize stringstream
    ss.str("");
    ss.clear();
}

void usage(){
    // just use it like cin, cout
    ss<<t;// put t into ss
    ss>>t;// put a token of value to t
}
