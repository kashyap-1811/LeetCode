class Solution {
public:
    int minOperations(string s) {
        int ops1 = 0, ops2 = 0;

        for(int i=0; i<s.size(); i++) {
            // started with 0
            if(i % 2 == 1 && s[i] != '1')
                ops1++;
            else if(i % 2 == 0 && s[i] != '0')
                ops1++;

            // started with 1
            if(i % 2 == 0 && s[i] != '1')
                ops2++;
            else if(i % 2 == 1 && s[i] != '0')
                ops2++; 
        }

        return min(ops1, ops2);
    }
};