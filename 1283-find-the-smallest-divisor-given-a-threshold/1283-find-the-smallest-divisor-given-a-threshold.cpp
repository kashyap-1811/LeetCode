class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1, end = *max_element(nums.begin(), nums.end());

        while(st <= end){
            int mid = (st + end) / 2;

            int count = 0;
            for(int i : nums){
                count += ceil((float)i / mid);
                if(count > threshold)
                    break;
            }

            if(count <= threshold)
                end = mid - 1;
            else
                st = mid + 1;
        }

        return st;
    }
};