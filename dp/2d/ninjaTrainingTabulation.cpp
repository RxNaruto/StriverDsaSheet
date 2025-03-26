#include<iostream>
#include<vector>
using namespace std;
int maxPoints(int day,int last,vector<vector<int> >&task,vector<vector<int> >&dp){
        dp[0][0]=max(task[0][1],task[0][2]);
        dp[0][1]=max(task[0][0],task[0][2]);
        dp[0][2]=max(task[0][0],task[0][1]);
        dp[0][3]=max(task[0][0],max(task[0][1],task[0][2]));
        
        for(int day=1;day<task.size();day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int points = task[day][i]+dp[day-1][i];
                        dp[day][last]=max(points,dp[day][last]);
                    }
                }


            }

        }
        return dp[task.size()-1][3];
   
    
}
int main()
{
    vector<vector<int> >task={{1,4,7},{3,0,7}};
    vector<vector<int> >dp(task.size(),vector<int>(task[0].size()+1,-1));
    
    cout<<maxPoints(1,3,task,dp);
 return 0;
}