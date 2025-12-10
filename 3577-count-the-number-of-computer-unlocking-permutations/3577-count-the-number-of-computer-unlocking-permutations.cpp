class Solution {
public:
    int countPermutations(vector<int>& c) {
        map<int, int> m;
        int min = INT_MAX;

        for (auto a : c) {
            m[a]++;
            if (min > a) {
                min = a;
            }
        }

        if (m[min] > 1 || min != c[0]) {
            return 0;
        } else {
            long long fact = 1;
            int mod = 1000000007;
            for (int i = 1; i <= c.size() - 1; i++) {
                fact = (fact * i) % mod;
            }
            return fact;
        }
    }
};