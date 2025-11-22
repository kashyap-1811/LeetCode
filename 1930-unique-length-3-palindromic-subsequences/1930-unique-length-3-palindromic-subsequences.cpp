class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        for(int i=0; i<=25; i++)
        {
            size_t first = s.find('a' + i);
            size_t last = s.rfind('a' + i);

            if(first != last)
            {
                set<char>c;
                for(int j=(first+1); j<last; j++)
                {
                    c.insert(s[j]);
                }

                count += c.size();
            }
        }

        return count;
    }
};