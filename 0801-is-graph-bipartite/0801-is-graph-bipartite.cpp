class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 1;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int j = 0; j < graph[curr].size(); j++) {
                        if (color[graph[curr][j]] == -1) {
                            q.push(graph[curr][j]);
                            color[graph[curr][j]] = !color[curr];
                        } else if (color[graph[curr][j]] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};