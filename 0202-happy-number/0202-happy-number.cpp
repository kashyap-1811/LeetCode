class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long>s;
        s.insert(n);
        int sum = 0;

        while(n != 1){
            sum = 0;

            while(n != 0){
                sum += pow(n%10, 2);
                n /= 10;
            }

            n = sum;
            if(s.find(n) != s.end())
                return false;
            s.insert({n});
        }

        return true;
    }
};