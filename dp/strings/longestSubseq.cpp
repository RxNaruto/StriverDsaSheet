class Solution {
    int longestSeq(string s1,string s2,int ind1,int ind2){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(s1[ind1]==s2[ind2]){
            return 1+longestSeq(s1,s2,ind1-1,ind2-1);
        }
        return max(longestSeq(s1,s2,ind1-1,ind2),longestSeq(s1,s2,ind1,ind2-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1= text1.length()-1;
        int l2=text2.length()-1;
        return longestSeq(text1,text2,l1,l2);
        
        
    }
};