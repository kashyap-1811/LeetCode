class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);
        vector<long long> nextFreeTime(n, 0);

        sort(meetings.begin(), meetings.end());

        for(auto &m : meetings){
            // check availability OR
            // if any room not available then check nearest next available room
            int k = -1;
            int minIdx = 0;

            for(int i=0; i<n; i++){
                if(nextFreeTime[i] <= m[0]){
                    k = i;
                    break;
                }
                if(nextFreeTime[i] < nextFreeTime[minIdx])
                    minIdx = i;
            }

            // update the count and nextFreeTime for the selected room
            if(k != -1){
                count[k]++;
                nextFreeTime[k] = m[1];
                //  cout << k << " " << nextFreeTime[k] << endl;
            }else{
                count[minIdx]++;
                nextFreeTime[minIdx] = nextFreeTime[minIdx] - m[0] + m[1];
                // cout << minIdx << " " << nextFreeTime[minIdx] << endl;
            }
        }

        int ans = 0;
        for(int i=1; i<n; i++){
            if(count[i] > count[ans])
                ans = i;
        }
        return ans;
    }
};

/* n = 4
12 44 -> room 0 [44]
13 30 -> room 1 [30]
21 49 -> room 2 [49]
24 44 -> room 3 [44]
27 37 -> 30 40 -> room 1 [40]
32 38 -> 40 46 -> room 1 [46]
46 49 -> room 0 [49]
48 49 -> room 1 [48]
*/