class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = (correct[0]*10 + correct[1] - current[0]*10 - current[1]);
        diff *= 60;
        diff += (correct[3]*10 + correct[4] - current[3]*10 - current[4]);

        int cnt = 0;
        cnt += (diff / 60);

        diff %= 60;
        cnt += (diff / 15);

        diff %= 15;
        cnt += (diff / 5);

        diff %= 5;
        cnt += (diff / 1);

        return cnt;
    }
};