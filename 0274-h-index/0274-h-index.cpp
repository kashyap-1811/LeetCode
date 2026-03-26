class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int val = 0;
        int hmax = 0;

        for(int i=0; i<n; i++) {
            while(val <= citations[i]) {
                if(n - i >= val)
                    hmax = val;
                else
                    break;
                val++;
            }

            if(val < citations[i])
                break;
        }

        return hmax;
    }
};