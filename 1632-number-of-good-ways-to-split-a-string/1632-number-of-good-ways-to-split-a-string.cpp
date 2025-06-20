class Solution {
public:
    int numSplits(string s) {
        map<int, int>right, left;

        for(int i=0; i<s.size(); i++)
            right[s[i]] = i;

        int count = 0;

        for(int i=0; i<s.size(); i++){
            left[s[i]] = i;
            
            if(right[s[i]] == i)
                right.erase(s[i]);

            if(left.size() == right.size()){
                // cout << s.substr(0, i) << " " << s.substr(i + 1) << endl;
                count++;
            }
        }

        return count;
    }
};