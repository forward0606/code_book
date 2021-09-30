1.given repeat elements set, to get non-repeated subset, we must sort.
(1) sort 
(2) if( i > startindex && c[i] == c[i-1])
         continue;
2.Use horizontal for loop and vertical recursion is very important to draw,
you can get some insight when drawing
3.When solving palindrome subset problem, you can still recurse it.
4.For more complicated subset such as increasing condition
int use[201]={0};
if(ans.back() > nums[i] || use[100 + nums[i]] == 1)
  continue;
5.bool dfs() {
    for loop 
       if(dfs())
         return true;
}
