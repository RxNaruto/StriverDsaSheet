#include<iostream>
#include<set>
using namespace std;
void unionSet(int arr1[],int arr2[],int s1,int s2){
    set<int>st;
    for(int i=0;i<s1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<s2;i++){
        st.insert(arr2[i]);
    }
    int uarr[st.size()];
    int i=0;
    for(auto it: st){
        uarr[i++]=it;
    }
    for(int i=0;i<st.size();i++){
        cout<<uarr[i]<<" ";
    }
}
int main()
{
   int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
int arr2[7] = {2,3,4,4,5,11,12};
unionSet(arr1,arr2,10,7);
 return 0;
}