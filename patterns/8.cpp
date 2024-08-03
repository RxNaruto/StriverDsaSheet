#include<iostream>
using namespace std;
int main()
{
    int nrows=5;
    for(int i=nrows;i>0;i--){
        for(int j=nrows-i;j>0;j--){
            cout<<" ";
        }
        for(int k=(i*2)-1;k>0;k--){
            cout<<"*";
        }
        for(int m=nrows-i;m>0;m--){
            cout<<" ";
        }
        cout<<endl;
    }
 return 0;
}