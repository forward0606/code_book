#include<queue> // header file of queue and priority_queue
#include<stack> // herder file of stack


// 宣告
queue<int> q;

priority_queue<int> pq;// max heap
priority_queue<int, vector<int>, greater<int>> pq;// min heap
//priority_queue 自訂排序法要寫 operator < and don't forget to add const
struct Point{
    int a, b;
    bool operator < (const Point& right)const{
        if(a != right.a)    return a < right.a;
        return b < b.right.b;
    }
}
priority_queue<Point> pq;

stack<int> st;

// usage

// add thing in it
    q.push(x);
    pq.push(x);
    st.push(x);
// access thing
    x = q.front();
    x = pq.top();
    x = st.top();
// take the thing out of it
    q.pop();
    pq.pop();
    st.pop();
// check empty
    q.empty();
// check size
    q.size();
