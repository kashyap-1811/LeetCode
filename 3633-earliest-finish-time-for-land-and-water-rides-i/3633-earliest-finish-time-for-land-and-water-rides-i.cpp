class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                // land slide first, water slide second
                if (landStartTime[i] + landDuration[i] >= waterStartTime[j]) 
                    minTime = min(minTime, landStartTime[i] + landDuration[i] + waterDuration[j]);
                else
                    minTime = min(minTime, waterStartTime[j] + waterDuration[j]);

                // water slide first, land slide second
                if (waterStartTime[j] + waterDuration[j] >= landStartTime[i])
                    minTime = min(minTime, waterStartTime[j] + waterDuration[j] + landDuration[i]);
                else
                    minTime = min(minTime, landStartTime[i] + landDuration[i]);
            }
        }

        return minTime;
    }
};