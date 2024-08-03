#include<iostream>
using namespace std;
int main()
{
    int nrows = 5;
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nrows-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<(2*i)+1;k++){
            cout<<"*";
        }
        for(int m=0;m<nrows-i-1;m++){
            cout<<" ";
        }
        cout<<endl;
    }
    
 return 0;
}
