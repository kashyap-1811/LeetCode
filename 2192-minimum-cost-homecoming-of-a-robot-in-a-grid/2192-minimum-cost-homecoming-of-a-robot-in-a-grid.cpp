class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, 
                vector<int>& rowCosts, vector<int>& colCosts) {
        int sr = startPos[0], sc = startPos[1];
        int hr = homePos[0], hc = homePos[1];
        int cost = 0;

        // Move along rows
        if (sr < hr) {
            for (int r = sr + 1; r <= hr; r++) cost += rowCosts[r];
        } else {
            for (int r = sr - 1; r >= hr; r--) cost += rowCosts[r];
        }

        // Move along cols
        if (sc < hc) {
            for (int c = sc + 1; c <= hc; c++) cost += colCosts[c];
        } else {
            for (int c = sc - 1; c >= hc; c--) cost += colCosts[c];
        }

        return cost;
    }
};
