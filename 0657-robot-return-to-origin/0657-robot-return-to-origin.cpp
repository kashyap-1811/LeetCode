class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;

        for(auto c : moves) {
            if(c == 'U')
                i++;
            else if(c == 'D')
                i--;
            else if(c == 'L')
                j--;
            else
                j++;
        }

        return !i && !j;
    }
};