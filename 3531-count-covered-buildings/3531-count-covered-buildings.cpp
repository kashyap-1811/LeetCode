class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int, set<int>> X, Y;

        for(int i=0; i<b.size(); i++){
            int x = b[i][0], y = b[i][1];
            X[x].insert({y});
            Y[y].insert({x});
        }

        int count = 0;
        for(auto &[x, s] : X){
            if(s.size() < 3)
                continue;

            auto it = next(s.begin());
            auto last = prev(s.end());

            while(it != last){
                int y = *it;
                auto &setY = Y[y];

                auto pointer = setY.find(x);
                if(pointer != setY.begin() && pointer != prev(setY.end()))
                    count++;

                it++;
            }
        }

        return count;
    }
};