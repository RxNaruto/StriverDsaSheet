#include<iostream>
using namespace std;
int sqrtOfNum(int number){
    int i =0;
    int ans=1;
    while(ans<=number){
        i++;
        ans=i*i;
        


    }
    return i-1;
}
int main()
{
    int num = 36;
    cout<<sqrtOfNum(num);
 return 0;
}