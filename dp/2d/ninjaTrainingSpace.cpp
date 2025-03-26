#include<iostream>
#include<vector>
using namespace std;
int maxPoints(int day,int last,vector<vector<int> >&task,vector<int>&dp){
        dp[0]=max(task[0][1],task[0][2]);
        dp[1]=max(task[0][0],task[0][2]);
        dp[2]=max(task[0][0],task[0][1]);
        dp[3]=max(task[0][0],max(task[0][1],task[0][2]));
        
        for(int day=1;day<task.size();day++){
            vector<int>temp(4,0);
            for(int last=0;last<4;last++){
                temp[last]=0;
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int points = task[day][i]+dp[i];
                        temp[last]=max(points,dp[last]);
                    }
                }


            }
            dp =temp;

        }
        return dp[3];
   
    
}
int main()
{
    vector<vector<int> >task={{1,4,7},{3,0,7}};
    vector<int>dp(4,-1);
    
    cout<<maxPoints(1,3,task,dp);
 return 0;
}