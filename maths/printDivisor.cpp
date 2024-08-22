#include<iostream>
using namespace std;
int printDivisor(int number){
    for(int i = 0;i<=number;i++){
        if(number%i==0){
            cout<<i<<" ";
        }
    }
}
int main(){
    int number = 36;
    printDivisor(number);

}