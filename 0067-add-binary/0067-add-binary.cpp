class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;

        // Process both strings from the end towards the beginning
        for (; i >= 0 && j >= 0; i--, j--) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 1) {
                    ans += '1';
                } else {
                    carry = 1;
                    ans += '0';
                }
            } else if (a[i] == '1' || b[j] == '1') {
                if (carry == 1) {
                    ans += '0';
                } else {
                    ans += '1';
                }
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry == 1) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                }
            }
        }

        // Process any remaining characters in a
        while (i >= 0) {
            if (a[i] == '1') {
                if (carry == 1) {
                    ans += '0';
                } else {
                    ans += '1';
                }
            } else {  // a[i] == '0'
                if (carry == 1) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                }
            }
            i--;
        }

        // Process any remaining characters in b
        while (j >= 0) {
            if (b[j] == '1') {
                if (carry == 1) {
                    ans += '0';
                } else {
                    ans += '1';
                }
            } else {  // b[j] == '0'
                if (carry == 1) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                }
            }
            j--;
        }

        // Add any remaining carry
        if (carry == 1) {
            ans += '1';
        }

        // Reverse the result to get the final binary sum
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
