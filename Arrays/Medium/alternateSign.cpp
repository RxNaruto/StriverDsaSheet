#include<iostream>
#include<vector>
using namespace std;
vector<int>alternateSign(vector<int>arr){
    int n= arr.size();
    vector<int>ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
        else{
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
    }
    return ans;
    

}
int main()
{
    vector<int> A = {1,2,-4,-5};
    vector<int> ans = alternateSign(A);
    for(int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }
 return 0;
}