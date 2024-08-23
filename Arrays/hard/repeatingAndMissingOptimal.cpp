#include<iostream>
#include<vector>
using namespace std;
void repeatingAndMissing(vector<int>arr){
    long long n = arr.size();
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1 = S-Sn;  //  x-y
    long long val2 = S2-S2n;    
    val2 = val2/val1;      //  x+y
    long long x = (val1+val2)/2;
    long long y =  x-val1;
    cout<<"repeating: "<<x<<" missing : "<<y<<endl;



}
int main()
{
     vector<int>arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    repeatingAndMissing(arr);
 return 0;
}