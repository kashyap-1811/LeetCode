class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        vector<int> startIdxs;

        for (int idx = 0; idx < len; idx++) {
            int startIdx = idx;

            unordered_map<string, pair<int, int>> mp;
            for (auto ss : words) {
                if (mp.count(ss))
                    mp[ss].first++;
                else
                    mp[ss] = {1, 0};
            }
            
            int count = 0;
            for (int i = idx; i < s.size(); i += len) {
                string ss = s.substr(i, len);
                // cout << ss << " ";

                if (mp.count(ss)) {
                    mp[ss].second++;
                    if (mp[ss].second == mp[ss].first)
                        count++;
                    while (mp[ss].second > mp[ss].first) {
                        string remove = s.substr(startIdx, len);
                        if (mp[remove].first == mp[remove].second)
                            count--;
                        mp[remove].second--;
                        startIdx += len;
                    }

                    if (count == mp.size()) {
                        startIdxs.push_back(startIdx);
                        string remove = s.substr(startIdx, len);
                        mp[remove].second--;
                        startIdx += len;
                        count--;
                    }
                } else {
                    while (startIdx < i + len) {
                        string remove = s.substr(startIdx, len);
                        if (mp.count(remove)) {
                            if (mp[remove].first == mp[remove].second)
                                count--;
                            mp[remove].second--;
                        }
                        startIdx += len;
                    }
                }

                // cout << startIdx << endl;
            }
            // cout << endl;
        }

        return startIdxs;
    }
};