#include<iostream>
using namespace std;
int main()
{
    int nrows=5;
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
    int nrows2=4;
    for(int i=nrows2;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        for(int s=0;s<nrows-i;s++){
            cout<<" ";
        }
        for(int s=0;s<nrows-i;s++){
            cout<<" ";
        }
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;

    }
 return 0;
}