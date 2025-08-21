class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<bool> take(asteroids.size(), false);
        stack<int> s;

        for(int idx=0; idx<asteroids.size(); idx++){
            int i = asteroids[idx];

            if(i > 0){
                s.push(idx);
            }else{
                while(!s.empty()){
                    if(asteroids[s.top()] < abs(i))
                        s.pop(); 
                    else if(asteroids[s.top()] == abs(i)){
                        s.pop();
                        i = 0;
                        break;
                    }else{
                        i = 0;
                        break;
                    }
                }

                if(i != 0)
                    take[idx] = true;
            }
        }

        while(!s.empty()){
            take[s.top()] = true;
            s.pop();
        }

        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++)
            if(take[i] == true)
                ans.push_back(asteroids[i]);

        return ans;
    }
};