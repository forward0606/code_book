#include <bits/stdc++.h>
using namespace std;
// the same angle problem.
// reference: https://www.youtube.com/watch?v=B2AJoQSZf4M
typedef long long int lld;
lld n;
struct point
{
    lld x,y,id;
}p[100006];
stack<point>dots;
lld smallest_id = 0;
point next_to_top();
bool cmp (point a, point b);
lld count_clockwise(int id, point top, point top_next);
int main ()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>p[i].x>>p[i].y;
        p[i].id = i+1;
        if(p[smallest_id].y == p[i].y){ //find the lowest y-coordinate and leftmost point, called P0
            if(p[smallest_id].x > p[i].x)
                smallest_id = i;
        }
        else if(p[smallest_id].y > p[i].y)
            smallest_id = i;
    }
    swap(p[0], p[smallest_id]); // p[0] is the lowest point and the leftmost of the same y coordinate.
    sort(p+1, p+n, cmp);
    // we have to do something to keep the farthest distance point.
    // if we sort the same angle by distance, and the longest distance be the next

    for(int i = 0; i < n; i++){
        while(dots.size() >= 2 && count_clockwise(i, dots.top(), next_to_top()) <= 0) // when count_clockwise == 0, we can replace the longer distance point to the array.
            dots.pop();
        dots.push(p[i]);
    }
    cout<<dots.size()+1<<endl; // all the vertex and the start point itself.
    cout<<p[0].id<<" ";
    while(!dots.empty())
    {
        cout<<dots.top().id<<" ";
        dots.pop();
    }
    cout<<endl;
}
bool cmp (point a, point b)
{
    lld x1 = a.x - p[0].x;
    lld y1 = a.y - p[0].y;
    lld x2 = b.x - p[0].x;
    lld y2 = b.y - p[0].y;
    lld z = x1*y2-x2*y1;
    if(z == 0){
        return x1*x1 + y1*y1 < x2*x2 + y2*y2;
    }
    return z > 0;
}
point next_to_top()
{
    point tmp = dots.top();
    dots.pop();
    point top_next = dots.top();
    dots.push(tmp);
    return top_next;
}
lld count_clockwise(int id, point top, point top_next) // actually we do the cross product XD.
{
    lld x1 = top.x - p[id].x;
    lld y1 = top.y - p[id].y;
    lld x2 = top.x - top_next.x;
    lld y2 = top.y - top_next.y;
    return x1*y2 - x2*y1;
}
