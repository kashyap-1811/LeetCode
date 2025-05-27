class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int currPairs = 1;
        int count = 0;

        for(int i=0; i<dominoes.size(); i++)
        {
            if(dominoes[i][0] > dominoes[i][1])
                swap(dominoes[i][0], dominoes[i][1]);
        }
        sort(dominoes.begin(), dominoes.end());

        // cout<<dominoes[0][0]<<" "<<dominoes[0][1]<<endl;

        for(int i=1; i<dominoes.size(); i++)
        {
            if(dominoes[i][0]==dominoes[i-1][0] && dominoes[i][1]==dominoes[i-1][1])
                currPairs++;
            else{
                count += ((currPairs*(currPairs-1))/2);
                currPairs = 1;
            }

            // cout<<dominoes[i][0]<<" "<<dominoes[i][1]<<endl;
        }

        count += ((currPairs*(currPairs-1))/2);

        return count;
    }
};