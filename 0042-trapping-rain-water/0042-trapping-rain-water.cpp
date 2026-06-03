class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        int lMax = height[0], rMax = height[n - 1];

        for (int i = 1, j = n - 2; i < n; i++, j--) {
            leftMax[i] = lMax;
            rightMax[j] = rMax;

            lMax = max(lMax, height[i]);
            rMax = max(rMax, height[j]);
        }

        int totalArea = 0;
        for (int i = 0; i < n; i++)
            totalArea += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        
        return totalArea;
    }
};