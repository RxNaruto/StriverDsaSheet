#include<iostream>
#include<vector>
#include<set>
using namespace std;
int fruitInBasket(vector<int>arr){
    int maxLen=INT_MIN;
    int size = arr.size();
    for(int i=0;i<size;i++){
        set<int>st;
        for(int j=i;j<size;j++){
            st.insert(arr[j]);
            if(st.size()<=2){
                maxLen = max(maxLen,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxLen;
    
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);

    cout<<fruitInBasket(arr);
 return 0;
}