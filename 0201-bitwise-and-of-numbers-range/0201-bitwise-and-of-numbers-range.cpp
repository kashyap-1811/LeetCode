class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        while (left != right) {
            result++;
            left >>= 1;
            right >>= 1;
        }
        return left << result;
    }
};