class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        int x = 0;
        
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++)
        {
            if(ans[x][1] >= intervals[i][0])
                ans[x][1] = max(ans[x][1], intervals[i][1]);
            else
            {
                ans.push_back(intervals[i]);
                x++;
            }
        }

        return ans;
    }
};