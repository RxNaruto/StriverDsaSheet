#include<iostream>
using namespace std;
void nNumbers(int n){
    if(n==0){
        return ;
    }
    cout<<n<<" ";
    nNumbers(n-1);
}
int main()
{
    nNumbers(10);

 return 0;
}