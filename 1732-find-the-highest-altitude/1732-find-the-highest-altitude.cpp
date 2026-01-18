class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int st = 0;
        int gm = 0;

        for(int i : gain){
            st += i;
            gm = max(gm, st);
        }

        return gm;
    }
};