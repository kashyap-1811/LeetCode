class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        queue<int> q;
        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0)
                return true;

            if(idx + arr[idx] < n && !vis[idx + arr[idx]]) {
                q.push(idx + arr[idx]);
                vis[idx + arr[idx]] = true;
            }

            if(idx - arr[idx] >= 0 && !vis[idx - arr[idx]]) {
                q.push(idx - arr[idx]);
                vis[idx - arr[idx]] = true;
            }
        }

        return false;
    }
};