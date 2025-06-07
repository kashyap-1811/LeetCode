// Custom comparator
struct Compare {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        if (a.first == b.first)
            return a.second < b.second; // max-heap for int
        return a.first > b.first;       // min-heap for char
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

        int n = s.size();
        vector<bool>vis(n, true);

        for(int i=0; i<n; i++)
        {
            if(s[i] == '*'){
                vis[i] = false;
                const pair<char, int>a = pq.top();
                pq.pop();
                vis[a.second] = false;
            }else{
                pq.push({s[i], i});
            }
        }

        string ans = "";

        for(int i=0; i<n; i++)
            if(vis[i])
                ans += s[i];

        return ans;
    }
};