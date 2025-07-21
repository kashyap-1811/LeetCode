class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int start = 0;
        int g = 0, c = 0;

        for(int i=0; i<gas.size(); i++){
            g += gas[i];
            c += cost[i];

            if(g < c){
                start = i+1;
                g = 0;
                c = 0;
            }

            // cout << g << " " << c << " " << start << endl;
        }

        return start < gas.size() ? start : -1;
    }
};