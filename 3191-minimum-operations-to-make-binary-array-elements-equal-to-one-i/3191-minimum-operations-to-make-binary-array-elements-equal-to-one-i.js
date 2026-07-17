/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let count = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
            if (i + 2 >= nums.length)
                return -1;

            nums[i] = 1;
            nums[i + 1] = !nums[i + 1];
            nums[i + 2] = !nums[i + 2];
            count++;
        }
    }

    return count;
};