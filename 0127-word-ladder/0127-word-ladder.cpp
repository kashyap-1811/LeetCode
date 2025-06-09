class Solution {
public: 
    bool difference(string s1, string s2){
        int diff = 0;

        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i] != s2[i])
                diff++;
        }

        return diff == 1 ? true : false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int steps = 1;

        queue<pair<string, int>>q;
        q.push({beginWord, -1});
        q.push({"LEVELUP", -1});

        vector<bool>vis(wordList.size(), false);

        while(!q.empty()){
            string currWord = q.front().first;
            int idx = q.front().second;
            q.pop();

            // cout<<currWord<<": ";

            if(currWord == "LEVELUP"){
                steps++;
                if(q.empty())
                    break;
                q.push({"LEVELUP", -1});
            }
            else if(currWord == endWord){
                return steps;
            }
            else{
                for(int i=0; i<wordList.size(); i++){
                    if(i!=idx && !vis[i] && difference(currWord, wordList[i])){
                        vis[i] = true;
                        q.push({wordList[i], i});
                    }
                }
            }
        }

        return 0;
    }
};