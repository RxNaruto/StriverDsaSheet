#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int wordLadder(string startWord,string endWord,vector<string>&wordList){
        queue<pair<string,int> >q;
        q.push({startWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endWord)return step;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;

            }
        }
        return 0;

    }
};
int main()
{
     vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
 return 0;
}