class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minimumDifference = INT_MAX;

        sort(arr.begin(), arr.end());

        for(int i=1; i<arr.size(); i++)
            minimumDifference = min(minimumDifference, arr[i] - arr[i-1]);

        vector<vector<int>>ans;

        for(int i=1; i<arr.size(); i++)
            if(arr[i]-arr[i-1] == minimumDifference)
                ans.push_back({arr[i-1], arr[i]});

        return ans;
    }
};