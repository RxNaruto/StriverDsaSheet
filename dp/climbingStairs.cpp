#include<iostream>
using namespace std;
int climbStairs(int n) {
    if(n==0)return 1;
    if(n==1)return 1;
    int left = climbStairs(n-1);
    int right = climbStairs(n-2);
    return left+right;

    
}
int main()
{
    cout<<climbStairs(3);
 return 0;
}