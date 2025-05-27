class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<int, int>m;

        for(int i=0; i<dominoes.size(); i++)
        {
            int no;
            if(dominoes[i][0] > dominoes[i][1])
                no = dominoes[i][0]*10 + dominoes[i][1];
            else
                no = dominoes[i][1]*10 + dominoes[i][0];

            if(m.find(no) != m.end())
                count += m[no];

            m[no]++;
        }

        return count;
    }
};