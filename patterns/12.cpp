#include<iostream>
using namespace std;
int main()
{
    int nrows=4;
    for(int i=1;i<=nrows;i++){
        for(int j=1;j<=i;j++){
            cout<<j;

        }
        for(int a=0;a<nrows-i;a++){
            cout<<" ";

        }
        for(int k=0;k<nrows-i;k++){
            cout<<" ";
        }
        for(int m=i;m>=1;m--){
            cout<<m;
        }
        cout<<endl;
    }
    
 return 0;
}