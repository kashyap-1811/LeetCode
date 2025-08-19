class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);

        for(int i=0; i<l.size(); i++){

            priority_queue<int> pq;
            for(int j=l[i]; j<=r[i]; j++){
                pq.push(nums[j]);
            }

            int u = pq.top();
            pq.pop();
            int diff = u - pq.top();
            u = pq.top();
            pq.pop();
            while(!pq.empty()){
                if(u - pq.top() != diff)
                    break;
                u = pq.top();
                pq.pop();
            }

            if(pq.empty())  ans[i] = true;
        }

        return ans;
    }
};