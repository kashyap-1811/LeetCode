class Solution {
public:
    map<int, vector<int>> mp;
    priority_queue<int> pq;

    void add(int w) {
        for(auto [c, vec] : mp) {
            if(c <= w) {
                for(int p : vec)
                    pq.push(p);
                mp.erase(c);
            } else break;
        }
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        for(int i=0; i<n; i++) {
            int c = capital[i];
            int p = profits[i];

            mp[c].push_back(p);
        }

        add(w);

        while(k-- && !pq.empty()) {
            w += pq.top();
            pq.pop();

            add(w);
        }

        return w;
    }
};