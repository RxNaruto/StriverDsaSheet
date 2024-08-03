#include<iostream>
using namespace std;
int main()
{
    int start =1;
    for(int i=0;i<6;i++){
        if(i%2==0){
               start=1;
            }
        else{
               start=0;
            }
        for(int j=0;j<i+1;j++){
            
            cout<<start;
            start=1-start;

        }
        cout<<endl;
    }
 return 0;
}