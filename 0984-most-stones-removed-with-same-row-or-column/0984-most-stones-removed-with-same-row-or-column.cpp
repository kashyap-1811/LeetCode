class Solution {
public:
    vector<int>par;

    int find(int x){
        if(x == par[x])
            return x;

        return par[x] = find(par[x]);
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);

        for(int i=0; i<n; i++)
            par[i] = i;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                        par[find(j)] = find(i);
                    }
                }
            }
        }

        int safeStones = 0;
        for(int i=0; i<n; i++)
            if(par[i] == i)
                safeStones++;

        return n - safeStones;
    }
};