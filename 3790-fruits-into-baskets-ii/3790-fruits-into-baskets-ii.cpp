class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        vector<bool>vis(baskets.size(), false);

        for(int i=0; i<fruits.size(); i++){
            int j = 0;
            for(; j<baskets.size(); j++){
                if(!vis[j] && baskets[j] >= fruits[i]){
                    vis[j] = true;
                    break;
                }
            }

            if(j == baskets.size())
                cnt++;
        }

        return cnt;
    }
};