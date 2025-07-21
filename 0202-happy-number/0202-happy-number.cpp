class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long>s;
        s.insert(n);

        long long nLong = n;
        long long sum = 0;

        while(nLong != 1){
            sum = 0;

            while(nLong != 0){
                sum += pow(nLong%10, 2);
                nLong /= 10;
            }

            nLong = sum;
            if(s.find(nLong) != s.end())
                return false;
            s.insert({nLong});
        }

        return true;
    }
};