#include<iostream>
using namespace std;
int main()
{
    
    for(int i=5;i>0;i--){
        for(char j='A';j<'A'+i;j++){
            cout<<j;
        }
        
        cout<<endl;
    }
 return 0;
}