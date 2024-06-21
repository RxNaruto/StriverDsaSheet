#include<iostream>
#include<vector>
using namespace std;
vector<int>twoSum(vector<int>& num,int target){
    vector<int>arr;
    for(int i=0;i<num.size()-1;i++){
        for(int j=i+1;j<num.size();j++){
            if(num[i]+num[j]==target){
                arr.push_back(i);
                arr.push_back(j);
                return arr;
            }
        }
    }
    arr.push_back(-1);
    arr.push_back(-1);
    return  arr;
}
int main()
{
    vector<int>arr={2,6,5,8,11};
    vector<int>arr2 =twoSum(arr, 14);
    cout<<arr2[0]<<endl;
    cout<<arr2[1]<<endl;

 return 0;
}