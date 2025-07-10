class Solution {
public:
    int lengthLongestPath(string input) {
        stack<pair<int, int>> s;  // {cumulative_length, depth}
        int len = 0, i = 0;

        while (i < input.size()) {
            int tabs = 0;

            // Skip '\n'
            while (i < input.size() && input[i] == '\n')
                i++;

            // Count '\t' to determine depth
            while (i < input.size() && input[i] == '\t') {
                tabs++;
                i++;
            }

            // Read the current name (file or folder)
            string word = "";
            while (i < input.size() && input[i] != '\n') {
                word += input[i];
                i++;
            }

            int wordSize = word.size() + 1; // +1 for '/' in path
            bool isFile = word.find('.') != string::npos;

            // Remove entries from stack deeper or equal to current depth
            while (!s.empty() && s.top().second >= tabs)
                s.pop();

            int currLen = wordSize;
            if (!s.empty())
                currLen += s.top().first;

            if (isFile)
                len = max(len, currLen - 1); // -1 to remove last '/'
            else
                s.push({currLen, tabs});
        }

        return len;
    }
};
