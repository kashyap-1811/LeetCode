class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int count = 0;
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        for(int i=0,j=0; i<players.size() && j<trainers.size();)
        {
            if(trainers[j] >= players[i++]){
                j++;
                count++;
            }
        }

        return count;
    }
};