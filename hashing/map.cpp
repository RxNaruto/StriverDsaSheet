//map<key,value>
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main()
{
    int arr[5]={1,2,5,3,5};
    unordered_map<int,int>mpp;
    map<int,int>mpp2;
    for(int i=0;i<5;i++){
        mpp[arr[i]]++;
    }
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    cout<<mpp[n];
 return 0;
}