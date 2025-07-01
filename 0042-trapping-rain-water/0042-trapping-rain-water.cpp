class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(height.begin(), height.end()), right(height.begin(), height.end());

        for(int i=1, j=n-2; i<n && j>=0; i++, j--){
            left[i] = max(left[i], left[i-1]);
            right[j] = max(right[j], right[j+1]);
        }

        int trappedWater = 0;
        for(int i=0; i<n; i++){
            if(height[i] < left[i] && height[i] < right[i])
                trappedWater += (min(left[i], right[i]) - height[i]);
        }

        return trappedWater;
    }
};