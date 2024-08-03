#include<iostream>
using namespace std;
int main()
{
    char ch='E';
    for(int i=0;i<5;i++){
        ch='E'-i;
        for(int j=0;j<i+1;j++){
            cout<<ch;
            ch++;
        }
        
        cout<<endl;
    }

 return 0;
}