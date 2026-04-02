class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoints = 0;

        for(auto p1 : points) {
            int denominatorZeroPoints = -1; // because this point will be counted
            unordered_map<double, int> mp;

            for(auto p2 : points) {
                if(p1[0] == p2[0]) {    // denominator zero
                    denominatorZeroPoints++;
                    continue;
                }

                double m = static_cast<double>(p2[1] - p1[1]) / (p2[0] - p1[0]);
                mp[m]++;
            }

            maxPoints = max(maxPoints, denominatorZeroPoints);
            for(auto [_, sameLinePoints] : mp)  
                maxPoints = max(maxPoints, sameLinePoints);
        }

        return maxPoints + 1; 
    }
};