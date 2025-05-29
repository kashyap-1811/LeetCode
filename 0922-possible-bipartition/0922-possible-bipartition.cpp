class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> lst(n + 1, vector<int>());

        for (int i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];

            lst[a].push_back(b);
            lst[b].push_back(a);
        }

        queue<int> q;
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 1;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int j = 0; j < lst[curr].size(); j++) {
                        if (color[lst[curr][j]] == -1) {
                            q.push(lst[curr][j]);
                            color[lst[curr][j]] = !color[curr];
                        } else if (color[lst[curr][j]] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};