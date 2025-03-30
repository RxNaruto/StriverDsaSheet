#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    private:
    int maxVal(vector<int>&val,vector<int>&wt,int maxWt,int index){
        if(index==0){
            if(maxWt>=wt[index])return val[0];
            else return 0;
        }
        int notPick = 0+ maxVal(val,wt,maxWt,index-1);
        int pick = INT_MIN;
        if(wt[index]<=maxWt){
            pick = val[index]+maxVal(val,wt,maxWt-wt[index],index-1);
        }
        return max(pick,notPick);
    }
    public:
    int knapsack(vector<int>&val,vector<int>&wt,int maxWt){
        return maxVal(val,wt,maxWt,val.size()-1);

    }
};

int main()
{
    vector<int>val={30,40,50};
    vector<int>wt={3,2,5};
    Solution obj;
    int maxWt = 6;
    cout<<obj.knapsack(val,wt,maxWt);
 return 0;
}