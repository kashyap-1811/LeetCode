class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> m;
        long long days = 0;

        for(int i=0; i<tasks.size(); i++){
            int t = tasks[i];

            // wait if gap < space
            if(m.count(t) && (days - m[t]) < space){
                days += (space - (days - m[t]));
            }

            // for completing this task
            days++;

            m[t] = days;
        }

        return days;
    }
};