class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;

        map<int, int> mp;
        for(int i : hand)
            mp[i]++;

        while(mp.size()) {
            if(mp.begin()->second == 0)
                mp.erase(mp.begin());
            else {
                auto it = mp.begin();
                it->second--;
                int cnt = 1;

                while(cnt < groupSize && ++it != mp.end() && it->first == mp.begin()->first + cnt && it->second != 0) {
                    cnt++;
                    it->second--;
                }

                if(cnt != groupSize)
                    return false;
            }
        }

        return true;
    }
};