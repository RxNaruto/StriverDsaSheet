#include<iostream>
using namespace std;
int factorial(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}
int main()
{
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    cout<<factorial(n);

 return 0;
}