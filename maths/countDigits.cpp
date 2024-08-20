#include<iostream>
using namespace std;
int countDigit(int digit){
    int count =0;
    while(digit>0){
        digit=digit/10;
        count++;

    }
    return count;
}
int main()
{
    int digit = 35;
    cout<<countDigit(digit);

 return 0;
}