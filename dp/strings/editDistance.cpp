class Solution {
    int minDis(string &s1,string &s2,int i,int j){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(s1[i]==s2[j]){
            return 0+minDis(s1,s2,i-1,j-1);
        }
        else{
            int ins = 1+minDis(s1,s2,i,j-1); //insertion
            int del = 1+minDis(s1,s2,i-1,j); //deletion
            int rep = 1+minDis(s1,s2,i-1,j-1); //replace

            return min(ins,min(del,rep));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return minDis(word1,word2,n-1,m-1);
        
    }
};