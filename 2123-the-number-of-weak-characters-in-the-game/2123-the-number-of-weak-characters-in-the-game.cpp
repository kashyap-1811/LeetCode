class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        auto lambda = [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(properties.begin(), properties.end(), lambda);
        int maxDef = 0, ans = 0;

        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < maxDef)
                ans++;
            else
                maxDef = max(maxDef, properties[i][1]);
            cout << properties[i][0] << " " << properties[i][1] << endl;
        }
        return ans;
    }
};