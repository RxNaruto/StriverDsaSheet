#include<iostream>
using namespace std;
int main()
{
    int nrows = 4;
    int i,j=0;
    for(i=0;i<nrows;i++){
        for(j=0;j<nrows;j++){
            if(i==0 || j==0 || i==nrows-1 || j==nrows-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
 return 0;
}