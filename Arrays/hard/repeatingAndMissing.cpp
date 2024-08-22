#include<iostream>
#include<vector>
using namespace std;
void repeatingAndMissing(vector<int>arr){
    int size = arr.size();
    int maxEl=*max_element(arr.begin(),arr.end());
    int missing,repeating;
    for(int i=1;i<=maxEl;i++){
        int count =0;
        for(int j=0;j<size;j++){
            if(i==arr[j]){
              count++;
            }
        }
        if(count==0){
            missing =i;
        }
        if(count==2){
            repeating=i;
        }

    }
    cout<<"missing: "<<missing<<endl;
    cout<<"repeating: "<<repeating<<endl;

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