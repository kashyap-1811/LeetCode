class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int minDist = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            if(m.count(n)){
                auto &v = m[n];
                if(v.size() < 3)
                    v.push_back(i);
                else{
                    v[0] = v[1];
                    v[1] = v[2];
                    v[2] = i;
                }
                
                if(v.size() == 3){
                    minDist = min(minDist, v[1]-v[0] + v[2]-v[1] + v[2]-v[0]);
                }
            }else{
                m[n] = {i};
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};