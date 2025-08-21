class Solution {
public:
    vector<int> par;

    int find(int x){
        if(x == par[x])
            return x;
        
        return par[x] = find(par[x]);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
        
        int extras = 0;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            int parU = find(u);
            int parV = find(v);

            if(parU == parV)
                extras++;
            else
                par[parU] = parV;
        }

        int groups = -1;
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            int parI = find(i);

            if(!s.count(parI)){
                groups++;
                s.insert({parI});
            }
        }

        return groups > extras ? -1 : groups;
    }
};