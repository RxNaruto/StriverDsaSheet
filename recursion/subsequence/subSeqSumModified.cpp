#include<iostream>
#include<vector>
using namespace std;
bool printSub(int ind,vector<int>&ds,int arr[],int sum,int x,int n){
    if(ind==n){
        if(sum==x){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
            
        }
        return false;
    }
    sum= sum+arr[ind];
    ds.push_back(arr[ind]);
    if(printSub(ind+1,ds,arr,sum,x,n)==true)return true;
    ds.pop_back();
    sum=sum-arr[ind];
    if(printSub(ind+1,ds,arr,sum,x,n)==true)return true;
    return false;

}
int main()
{
    int arr[3]={3,1,2};
    int n =3;
    int x =3;
    vector<int>ds;
    int sum=0;
    printSub(0,ds,arr,sum,x,3);
 return 0;
}