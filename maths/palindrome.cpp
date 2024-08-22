#include<iostream>
using namespace std;
bool palindrome(int number){
    int num,ans=0;
    while(number>0){
        num=number%10;
        ans=ans*10+num;
        number=number/10;

    }
   

}
int main()
{
 return 0;
}