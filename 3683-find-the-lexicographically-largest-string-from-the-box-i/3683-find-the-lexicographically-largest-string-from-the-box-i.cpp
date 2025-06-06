class Solution {
public:
    bool lexicographicalLarger(string ans, string temp)
    {
        for(int i=0,j=0; i<ans.size() && j<temp.size(); i++, j++){
            if(ans[i] < temp[j])
                return true;
            else if(ans[i] > temp[j])
                return false;
        }

        return ans.size() > temp.size() ? false : true;
    }

    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;

        int n = word.size();
        int m = n - numFriends + 1; //max length word
        string ans = word.substr(0, m);

        for(int i=1; i<word.size(); i++)
        {
            string temp = word.substr(i, m);
            if(lexicographicalLarger(ans, temp))
                ans = temp;
        }

        return ans;
    }
};