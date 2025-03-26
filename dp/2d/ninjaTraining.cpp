#include<iostream>
#include<vector>
using namespace std;
int maxPoints(int day,int last,vector<vector<int> >&task){
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,task[0][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int points=task[day][i]+maxPoints(day-1,i,task);
            maxi=max(points,maxi);
        }
    }
    return maxi;
    
}
int main()
{
    vector<vector<int> >task={{1,4,7},{3,0,7}};
    cout<<maxPoints(1,3,task);
 return 0;
}