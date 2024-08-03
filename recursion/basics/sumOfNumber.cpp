#include<iostream>
using namespace std;
int sumOfNumber(int n){
    if(n==1){
        return 1;
    }
    return sumOfNumber(n-1)+n;
}
int main()
{
    int n=5;
    cout<<sumOfNumber(n)<<endl;

 return 0;
}