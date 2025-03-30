#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    int knapsack(vector<int>&val,vector<int>&wt,int maxWt){
        vector<int>prev(maxWt+1,0),curr(maxWt+1,0);
        for(int i=wt[0];i<=maxWt;i++){
            prev[i]=val[0];
        }
        for(int i=1;i<val.size();i++){
            for(int w=0;w<=maxWt;w++){
                int notPick = 0+prev[w];
                int pick = INT_MIN;
                if(wt[i]<=w){
                    pick =  val[i]+prev[w-wt[i]];
                }
                curr[w]=max(notPick,pick);
                
                
            }
            prev = curr;
        }
        return prev[maxWt];
        
        

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