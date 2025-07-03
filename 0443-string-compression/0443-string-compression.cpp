class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 1;
        int x = 0;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1])
                len++;
            else {
                if (len == 1) {
                    chars[x++] = chars[i - 1];
                } else {
                    chars[x++] = chars[i - 1];
                    int k = x;
                    while (len > 0) {
                        chars[x++] = (len % 10 + '0');
                        len /= 10;
                    }
                    reverse(chars.begin()+k, chars.begin()+x);
                }
                len = 1;
            }
        }

        if (len == 1) {
            chars[x++] = chars[chars.size() - 1];
        } else {
            chars[x++] = chars[chars.size() - 1];
            int k = x;
            while (len > 0) {
                chars[x++] = (len % 10 + '0');
                len /= 10;
            }
            reverse(chars.begin()+k, chars.begin()+x);
        }

        return x;
    }
};