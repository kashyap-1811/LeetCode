class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for (int i = 0; i < n; i++) {
            // Flip the i-th bit of the i-th string
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};