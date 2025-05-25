class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;

        for (string i : words)
            m[i]++;

        int count = 0;
        bool doublecheck = false;

        for (auto it : m) 
        {
            string rev;
            rev += it.first[1];
            rev += it.first[0];

            // cout<<it.first<<" "<<it.second<<" "<<rev<<" "<<m[rev]<<" ";

            if (it.first[0] == it.first[1])
            {
                count += (it.second-1);
                if(it.second%2==1 && !doublecheck)
                {
                    count += 1;
                    doublecheck = true;
                }
                else if(it.second%2 == 0)
                    count++;
            }
            else if (m.find(rev) != m.end())
                count += min(it.second, m[rev]);
            // cout<<count<<endl;
        }

        return count*2;
    }
};