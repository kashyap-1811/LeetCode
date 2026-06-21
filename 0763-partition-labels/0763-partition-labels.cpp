class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            last[s[i] - 'a'] = i;
            first[s[j] - 'a'] = j;
        }

        vector<vector<int>> intervals;
        for (int i = 0; i < 26; i++)
            if (first[i] != -1)
                intervals.push_back({first[i], last[i]});
        
        sort(intervals.begin(), intervals.end());

        vector<int> partitionLengths;
        int start = intervals[0][0];
        int end = intervals[0][1];
    
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end)
                end = max(end, intervals[i][1]);
            else {
                partitionLengths.push_back(end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        partitionLengths.push_back(end - start + 1);
        return partitionLengths;
    }
};