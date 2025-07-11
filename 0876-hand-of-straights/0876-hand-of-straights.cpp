class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>m;
        for(int i : hand)
            m[i]++;

        while(!m.empty()){
            auto ub = m.upper_bound(-1);
            int num = ub->first;
            m[num]--;

            if(m[num] == 0)
                m.erase(num);

            for(int i=1; i<groupSize; i++){
                if(m.find(num + 1) == m.end())
                    return false;
                else{
                    m[num + 1]--;
                    if(m[num + 1] == 0)
                        m.erase(num + 1);
                    num++;
                }
            }
        }

        return true;
    }
};