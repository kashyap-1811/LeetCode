class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = -1;
        int count = 0;

        for(int i : nums) {
            if (count == 0)
                element = i;

            if (element == i)
                count++;
            else
                count--;
        }

        return element;
    }
};