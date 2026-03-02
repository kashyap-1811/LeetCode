class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> m;

        // Count the frequency of each element
        for (int num : nums) {
            m[num]++;
        }

        // Reverse iterate over the map
        int count = 0;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            count += it->second;  // Add the frequency of the current element

            if (count >= k) {
                return it->first;  // Return the element when we've reached the k-th largest
            }
        }

        return -1;  // If k is out of bounds
    }
};
