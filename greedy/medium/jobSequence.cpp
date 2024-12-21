#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job{
    int id,deadline,profit;
};

bool compare(Job a,Job b){
    return (a.profit> b.profit);
}
pair<int,int> jobScheduling(vector<Job>jobs){
    sort(jobs.begin(),jobs.end(),compare);
    int size = jobs.size();
    int totalProfit = 0,cnt =0,maxDeadline=-1;
    for(int i=0;i<size;i++){
        maxDeadline = max(maxDeadline,jobs[i].deadline);


    }
    vector<int>slot(maxDeadline+1,-1);
    int jobCount =0;
    for(int i=0;i<jobs.size();i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(slot[j]==-1){
                slot[j]=jobs[i].id;
                totalProfit+=jobs[i].profit;
                jobCount++;
                break;
            }

        }
    }
    return make_pair(jobCount,totalProfit);

}
int main()
{
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    // Call the jobScheduling function
    pair<int, int> result = jobScheduling(jobs);
    cout << "Number of jobs done: " << result.first << "\nTotal Profit: " << result.second << endl;

 return 0;
}