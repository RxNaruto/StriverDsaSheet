#include<iostream>
using namespace std;
void nNames(int i,int n){
    if(i>n){
        return ;
        
    }
    cout<<"naruto"<<endl;
    nNames(i+1,n);
}
int main()
{
   nNames(1,5);
    
 return 0;
}