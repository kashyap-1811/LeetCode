class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long half = num/3;

        if(half*3 == num)
            return vector<long long>{half-1, half, half+1};
        else
            return vector<long long>{};
    }
};