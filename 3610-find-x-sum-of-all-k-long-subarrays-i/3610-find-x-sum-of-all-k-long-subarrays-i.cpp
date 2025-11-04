class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(i >= k)
                m[nums[i - k]]--;

            if(i >= k-1){
                priority_queue<pair<int, int>> pq;
                for(auto p : m)
                    pq.push({p.second, p.first});
                
                int sum = 0;
                int elements = 0;
                while(!pq.empty() && elements < x){
                    elements++;
                    sum += pq.top().second * pq.top().first;
                    pq.pop();
                }

                ans.push_back(sum);
            }
        }

        return ans;
    }
};