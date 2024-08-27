#include<iostream>
using namespace std;
int nthRoot(int n,int m){
    for(int i=0;i<m;i++){
        int ans = pow(i,i);
        if(ans ==m)return i;
        else if(ans>m)return -1;

    }
    return 0;
}
int main()
{
    int n = 4, m =69;
    cout<<nthRoot(n,m);
 return 0;
}