class Solution {
public:
    const int mod = 1e9 + 7;
    
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int>m;
        for(auto point : points)
            m[point[1]]++;

        long long cnt = 0;
        int totalPairs = 0;

        for(auto it : m){
            int size = it.second;
            long long currPairs = (1LL * size * (size - 1) / 2);
            
            if(size > 1){
                cnt += (currPairs * totalPairs);
                cnt %= mod;
                totalPairs += currPairs;
            }
        }        

        return cnt;
    }
};