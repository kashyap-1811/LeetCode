class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        queue<int> q;
        int maxLength = 0;
        int curr = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == t[i])
                curr++;
            else{
                int diff = abs(s[i] - t[i]);

                while(maxCost < diff && !q.empty()){
                    int idx = q.front();
                    q.pop();

                    maxCost += abs(s[idx] - t[idx]);
                    curr = i - idx - 1;
                }

                if(maxCost >= diff){
                    q.push(i);
                    maxCost -= diff;
                    curr++;
                }else   curr = 0;
            }

            maxLength = max(maxLength, curr);
        }

        return maxLength;
    }
};