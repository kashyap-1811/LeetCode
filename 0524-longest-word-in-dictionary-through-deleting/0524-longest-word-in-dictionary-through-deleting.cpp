class Solution {
public:
    // helper: check if "word" is a subsequence of "s"
    bool isSubsequence(const string& s, const string& word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        // sort dictionary by length desc, then lexicographically asc
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });

        // check words in sorted order
        for (string& word : dictionary) {
            if (isSubsequence(s, word)) return word;
        }

        return "";
    }
};
