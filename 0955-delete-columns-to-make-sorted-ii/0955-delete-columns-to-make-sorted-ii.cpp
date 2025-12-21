class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        vector<bool> nextEqual(strs.size(), true);

        for (int idx = 0; idx < strs[0].size(); idx++) {
            for (int i = 1; i < strs.size(); i++) {
                if (nextEqual[i-1] && strs[i][idx] < strs[i - 1][idx]) 
                {
                    cnt++;
                    for (int k = 0; k < strs.size(); k++)
                        strs[k][idx] = 'z';
                    break;
                }
            }

            for (int i = 1; i < strs.size(); i++){
                if(strs[i][idx] != strs[i-1][idx])
                    nextEqual[i-1] = false;
            }
        }

        return cnt;
    }
};