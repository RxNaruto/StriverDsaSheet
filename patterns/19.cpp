#include<iostream>
using namespace std;
int main()
{
    int nrows= 5;
    for(int i=0;i<nrows;i++){
        for(int j=nrows-i;j>0;j--){
            cout<<"*";
        }
        for(int s=0;s<2*i;s++){
            cout<<" ";
        }
        for(int k=nrows-i;k>0;k--){
            cout<<"*";
        }
        cout<<endl;


    }
    for(int i=0;i<nrows;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int s=0;s<nrows-i-1;s++){
            cout<<" ";
        }
        for(int s=0;s<nrows-i-1;s++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
 return 0;
}