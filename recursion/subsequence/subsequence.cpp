#include<iostream>
#include<vector>
using namespace std;
void printSub(int ind,vector<int>&ds,int arr[],int n){
    if(ind==n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<endl;
    return;
    }
    
    ds.push_back(arr[ind]);
    printSub(ind+1,ds,arr,n);
    ds.pop_back();
    printSub(ind+1,ds,arr,n);



}
int main()
{
    int arr[3]={3,1,2};
    int n=3;
    vector<int>ds;
    printSub(0,ds,arr,n);

 return 0;
}