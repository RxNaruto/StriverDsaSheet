#include<iostream>
using namespace std;
void nNumbers(int n){
    if(n==0){
        return ;
    }
    nNumbers(n-1);
    cout<<n<<" ";
}
int main()
{
    nNumbers(10);

 return 0;
}