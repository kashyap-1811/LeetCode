class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;

        for (int idx = 0; idx < strs[0].size(); idx++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].substr(0, idx) == strs[i - 1].substr(0, idx) &&
                    strs[i][idx] < strs[i - 1][idx]) 
                    {
                    cnt++;
                    for (int k = 0; k < strs.size(); k++)
                        strs[k][idx] = 'z';
                    break;
                }
            }
        }

        return cnt;
    }
};