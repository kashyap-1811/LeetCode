class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n, -1), right(n, n);
        stack<int>s;

        //right smaller
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            
            if(s.empty())
                right[i] = n;
            else
                right[i] = s.top();

            s.push(i);
        }

        while(!s.empty())
            s.pop();

        //left smaller
        s.push(0);
        for(int i=1; i<n; i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            
            if(s.empty())
                left[i] = -1;
            else
                left[i] = s.top();

            s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            cout<<left[i]<<" "<<right[i]<<endl;
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};