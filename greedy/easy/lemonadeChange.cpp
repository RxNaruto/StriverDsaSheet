#include<iostream>
#include<vector>
using namespace std;
bool lemonadeChange(vector<int>arr){
    int size = arr.size();
    int five = 0,ten = 0;
    int i=0;
    while(i<size){
        if(arr[i]==5){
            five ++;
        }
        else if(arr[i]==10){
            if(five){
                five=five-1;
                ten = ten+1;
            }
            else{
                return false;
            }
        }
        else{
            if(five && ten){
                five = five-1;
                ten = ten-1;
            }
            else if(five>=3){
                five = five-3;
            }
            else{
                return false;
            }
        }
        i++;
    }
    return true;
}
int main()
{
    vector<int>arr;
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(20);
    cout<<lemonadeChange(arr);
 return 0;
}