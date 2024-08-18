#include<iostream>
using namespace std;
int powN(int x,int n ){
    
    if(n==0){
        return 1;
    }
    return powN(x,n-1)*x;
}
int main()
{
    cout<<powN(3,2);

 return 0;
}

