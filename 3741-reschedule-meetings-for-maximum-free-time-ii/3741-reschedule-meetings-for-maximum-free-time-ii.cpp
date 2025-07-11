class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freeTime;

        // free time before the first event
        freeTime.push_back(startTime[0]);

        // free time between consecutive events
        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }

        // free time after the last event
        freeTime.push_back(eventTime - endTime[n - 1]);

        vector<int> maxFreeLeft(n, 0), maxFreeRight(n, 0);

        // Calculate max free time available to the right of each event
        int currMax = freeTime[n];  // last free time
        for (int i = n - 2; i >= 0; i--) {
            currMax = max(currMax, freeTime[i + 2]);
            maxFreeRight[i] = currMax;
        }

        // Calculate max free time available to the left of each event
        currMax = freeTime[0];
        for (int i = 1; i < n; i++) {
            currMax = max(currMax, freeTime[i - 1]);
            maxFreeLeft[i] = currMax;
        }

        // Find maximum free time considering shifting events
        int maxFree = 0;
        for (int i = 0; i < n; i++) {
            int duration = endTime[i] - startTime[i];
            bool canShift = maxFreeLeft[i] >= duration || maxFreeRight[i] >= duration;
            int combinedFree = freeTime[i] + freeTime[i + 1] + (canShift ? duration : 0);
            maxFree = max(maxFree, combinedFree);
        }

        return maxFree;
    }
};