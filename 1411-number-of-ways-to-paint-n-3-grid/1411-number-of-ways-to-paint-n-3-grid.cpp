class Solution {
public:
    static const int mod = 1e9 + 7;

    int numOfWays(int n) {
        long long same = 6;  // ABA patterns
        long long diff = 6;  // ABC patterns

        for(int i = 2; i <= n; i++){
            long long newSame = (same * 3 + diff * 2) % mod;
            long long newDiff = (same * 2 + diff * 2) % mod;
            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % mod;
    }
};
