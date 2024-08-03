#include<iostream>
using namespace std;
int main()
{
    int nrows=6;
    for(int i=0;i<2*nrows-1;i++){
        for(int j=0;j<2*nrows-1;j++){
            if(j==0 || j==nrows-1 || i==0 || i==nrows-1){
                cout<<nrows;
            }
            else if(j==1 || j==nrows-2 || i==0 || i==nrows-2){
                cout<<nrows-1;
            }
            else if(j==2 || j==nrows-3 || i==0 || i==nrows-3){
                cout<<nrows-2;
            }
        }
        cout<<endl;
    }
 return 0;
}