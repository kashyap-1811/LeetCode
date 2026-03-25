class Solution {
public:
    string simplifyPath(string path) {
        string word = "";
        stack<string> s;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (word.size() == 0 || word == ".")
                    ;
                else if (word == "..") {
                    if (!s.empty())
                        s.pop();
                } else {
                    s.push(word);
                }
                word = "";
            } else {
                word += path[i];
            }
        }

        if (word.size() == 0 || word == ".")
            ;
        else if (word == "..") {
            if (!s.empty())
                s.pop();
        } else {
            s.push(word);
        }

        stack<string> s2;
        while (!s.empty()) {
            s2.push(s.top());
            s.pop();
        }

        string ans = "/";
        while (!s2.empty()) {
            ans += s2.top();
            ans += "/";
            s2.pop();
        }

        if (ans.size() > 1)
            ans.pop_back();
        return ans;
    }
};