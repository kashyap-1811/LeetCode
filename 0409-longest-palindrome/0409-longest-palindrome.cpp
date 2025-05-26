class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>m;

        for(char c : s)
            m[c]++;

        bool check = false;
        int count = 0;

        for(auto it : m)
        {
            if(it.second % 2 == 1)
            {
                count += (it.second-1);
                if(check == false)
                {
                    count++;
                    check = true;
                }
            }
            else count += it.second;
        }

        return count;
    }
};