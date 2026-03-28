class Solution {
public:
    int diff(string curr, string s) {
        int cnt = 0;
        for(int i=0; i<8; i++)
            if(curr[i] != s[i])
                cnt++;

        return cnt;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        q.push("nullptr");
        int minSteps = 0;
        unordered_set<string> us;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr == "nullptr") {
                if (q.empty())
                    return -1;
                q.push("nullptr");
                minSteps++;
            } else if (curr == endGene) {
                break;
            } else {
                for (string s : bank) {
                    if (!us.count(s) && diff(curr, s) == 1) {
                        q.push(s);
                        us.insert(s);
                    }
                }
            }
        }

        return minSteps;
    }
};