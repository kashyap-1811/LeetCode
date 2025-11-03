class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<bool> bursted(n, false);

        int time = 0;
        int j = 0;
        for(int i=1; i<colors.size(); i++){
            bool upgradeJ = true;

            if(colors[i] == colors[j]){
                if(neededTime[i] < neededTime[j]){
                    time += neededTime[i];
                    bursted[i] = true;
                    upgradeJ = false;
                }else{
                    time += neededTime[j];
                    bursted[j] = true;
                }
            }

            if(upgradeJ){
                 j++;
                while(bursted[j])
                    j++;
            }
        }

        return time;
    }
};