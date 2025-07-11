class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;

        // Populate the initial queues
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        // Simulate the voting process
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d)
                radiant.push(r + n); // R bans D
            else
                dire.push(d + n);    // D bans R
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
