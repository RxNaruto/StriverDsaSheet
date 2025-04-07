class Solution {
    private:
    int minC(int i,int j,vector<int>&cuts){
        if(i>j)return 0;
        int mine = INT_MAX;
        for(int ind = i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1]+
            minC(i,ind-1,cuts)+minC(ind+1,j,cuts);
             mine = min(mine,cost);
        }
        return mine;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
            int c = cuts.size();
        return minC(1,c-2,cuts);

        
    }
};