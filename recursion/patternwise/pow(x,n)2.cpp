#include<iostream>
using namespace std;
double powN(double x,int n){
    double ans = 1.0;
    for(int i=0;i<n;i++){
        ans*=x;
    }
    return ans;
}
int main()
{
   cout<<powN(2,10);
 return 0;
}