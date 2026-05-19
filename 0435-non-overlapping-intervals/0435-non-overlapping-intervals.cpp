class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int last = 0;
        int count = 0;

        for(int i = 1; i<intervals.size(); i++) {
            if(intervals[last][1] > intervals[i][0]) {
                count++;
                if(intervals[last][1] > intervals[i][1])
                    last = i;
            } else
                last = i;
        }

        return count;
    }
};