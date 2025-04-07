class Solution {
    int maxS(vector<int>&arr,int k,int ind,int n){
        if(ind ==n)return 0;
        int maxA=INT_MIN;
        int len=0,maxi=INT_MIN;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len*maxi)+maxS(arr,k,j+1,n);
            maxA=max(sum,maxA);
        }
        return maxA;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return maxS(arr,k,0,arr.size());
        
    }
};