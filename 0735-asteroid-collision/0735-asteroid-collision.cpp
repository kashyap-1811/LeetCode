class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for(int a : asteroids){
            if(a < 0){
                while(!st.empty() && st.top() < abs(a))
                    st.pop();

                if(st.empty())
                    ans.push_back(a);
                else if(st.top() == abs(a))
                    st.pop();
            }else{
                st.push(a);
            }
        }

        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }

        return ans;
    }
};