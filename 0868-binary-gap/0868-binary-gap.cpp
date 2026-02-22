class Solution {
public:
    int binaryGap(int n) {
        int right = -1, left = -1;
        int idx = 0;
        int ans = 0;

        while (n != 0) {
            if (n % 2 == 1) {
                if (left == -1)
                    left = idx;
                else if(right == -1)
                    right = idx;
                else{
                    left = right;
                    right = idx;
                }
                ans = max(ans, right - left);
            }
            n /= 2;
            idx++;
        }

        return ans;
    }
};