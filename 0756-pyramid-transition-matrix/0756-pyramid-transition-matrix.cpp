class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> dead;

    void buildNext(
        int idx,
        const string& bottom,
        string& current,
        vector<string>& nextLevels
    ) {
        if (idx == bottom.size() - 1) {
            nextLevels.push_back(current);
            return;
        }

        string key;
        key.push_back(bottom[idx]);
        key.push_back(bottom[idx + 1]);

        if (mp.find(key) == mp.end())
            return;

        for (char c : mp[key]) {
            current.push_back(c);
            buildNext(idx + 1, bottom, current, nextLevels);
            current.pop_back();
        }
    }

    bool dfs(const string& bottom) {
        if (bottom.size() == 1)
            return true;

        if (dead.count(bottom))
            return false;

        vector<string> nextLevels;
        string current;
        buildNext(0, bottom, current, nextLevels);

        for (const string& nxt : nextLevels) {
            if (dfs(nxt))
                return true;
        }

        dead.insert(bottom);
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& s : allowed) {
            string key;
            key.push_back(s[0]);
            key.push_back(s[1]);
            mp[key].push_back(s[2]);
        }

        return dfs(bottom);
    }
};
