#include<iostream>
#include<vector>
using namespace std;
int maxPoints(int day,int last,vector<vector<int> >&task,vector<vector<int> >&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,task[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int points=task[day][i]+maxPoints(day-1,i,task,dp);
            maxi=max(points,maxi);
        }
    }
    return dp[day][last]=maxi;
    
}
int main()
{
    vector<vector<int> >task={{1,4,7},{3,0,7}};
    vector<vector<int> >dp(task.size(),vector<int>(task[0].size()+1,-1));
    cout<<maxPoints(1,3,task,dp);
 return 0;
}