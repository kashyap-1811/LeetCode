class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);

        set<int> s;
        s.insert(heights[n-1]);

        for(int i=n-2; i>=0; i--) {
            if(heights[i] <= heights[i+1]) 
                ans[i] = 1;
            else {
                auto it = s.lower_bound(heights[i]);

                if(it == s.end()){
                    ans[i] = s.size();
                    s.clear();
                } 
                else {
                    int count = 1;
                    for(auto iterator=s.begin(); iterator!=it; iterator++) {
                        count++;
                        s.erase(iterator);
                    }
                    ans[i] = count;
                }
            }

            s.insert(heights[i]);
            // for(auto iterator=s.begin(); iterator!=s.end(); iterator++)
            //     cout << *iterator << " ";
            // cout << endl;
         }

        return ans;
    }
};