#include<iostream>
using namespace std;
int reverseNumber(int number){
    int num,ans=0;
    while(number>0){
        num=number%10;
        ans=ans*10+num;
        number=number/10;

    }
    return ans;
}
int main()
{
    int num=12345;
    cout<<reverseNumber(num);
 return 0;
}