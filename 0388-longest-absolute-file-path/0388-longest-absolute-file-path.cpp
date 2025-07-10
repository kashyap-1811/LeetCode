class Solution {
public:
    int lengthLongestPath(string input) {
        stack<pair<int, int>> s;  // {cumulative_length, depth}
        int maxLen = 0, i = 0;

        while (i < input.size()) {
            int depth = 0;

            // Count tabs
            while (i < input.size() && input[i] == '\n') i++;
            while (i < input.size() && input[i] == '\t') {
                depth++;
                i++;
            }

            // Read current word
            string name = "";
            while (i < input.size() && input[i] != '\n') {
                name += input[i];
                i++;
            }

            bool isFile = name.find('.') != string::npos;
            int nameLen = name.length() + 1; // +1 for '/'

            // Remove deeper/equal directories from stack
            while (!s.empty() && s.top().second >= depth)
                s.pop();

            int totalLen = nameLen;
            if (!s.empty())
                totalLen += s.top().first;

            if (isFile)
                maxLen = max(maxLen, totalLen - 1);  // -1 to remove last '/'
            else
                s.push({totalLen, depth});
        }

        return maxLen;
    }
};
