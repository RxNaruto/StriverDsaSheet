#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution{
    public:
    vector<vector<string> >findSequence(string startWord,string endWord,
    vector<string>& wordList){
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string> >q;
        q.push({startWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(startWord);
        int level = 0;
        vector<vector<string> > ans;
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char originalWord = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=originalWord;


            }
        }
        return ans;

    }
    
};
int main()
{
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findSequence(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
 return 0;
}