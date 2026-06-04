class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t idx;
        while((idx = s.find(part)) != string::npos)
            s.erase(idx, part.size());
        return s;
    }
};