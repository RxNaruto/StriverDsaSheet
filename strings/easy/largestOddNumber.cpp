#include<iostream>
#include<string>
using namespace std;
string largestOddNumber(string num) {
        int max=0;
        int n = stoi(num);
        while(n>0){
            int t = n%10;
            if(t%2!=0){
             if(t>max){
                max=t;
             }
             
            }
            n/10;
            


        }
        if(max==0){
            return "";
        }
        return to_string(max);
        
        
    }
int main()
{
    cout<<largestOddNumber("52");


 return 0;
}