#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meeting{
    int start;
    int end;
    int pos;
};

bool comparator(Meeting m1, Meeting m2){
    if(m1.end < m2.end)return true;
    else if(m1.end>m2.end)return false;
    else{
        return m1.pos<m2.pos;
    }

}
vector<int>maxMeeting(vector<int>start,vector<int>end){
    vector<Meeting>meeting;
    int size = start.size();
    for(int i=0;i<size;i++){
        meeting.push_back({start[i],end[i],i+1});

    }
    sort(meeting.begin(),meeting.end(),comparator);
    vector<int>ans;
    int limit = meeting[0].end;
    ans.push_back(meeting[0].pos);

    for(int i=1;i<size;i++){
        if(meeting[i].start>limit){
            ans.push_back(meeting[i].pos);
            limit = meeting[i].end;
        }
    }
    return ans;
}
int main()
{
    vector<int>start;
    vector<int>end;
    start.push_back(1);
    start.push_back(3);
    start.push_back(0);
    start.push_back(5);
    start.push_back(8);
    start.push_back(5);
    end.push_back(2);
    end.push_back(4);
    end.push_back(5);
    end.push_back(7);
    end.push_back(9);
    end.push_back(9);
    vector<int>ans=maxMeeting(start,end);
    for(auto itr: ans){
        cout<<itr<<" ";
    }

 return 0;
}