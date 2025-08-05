class Solution {
public:
    int maximum69Number (int num) {
        stack<int>s;

        while(num > 0){
            s.push(num % 10);
            num /= 10;
        }

        int ans = 0;
        while(!s.empty()){
            ans *= 10;
            ans += 9;
            if(s.top() == 6){
                s.pop();
                break;
            }
            s.pop();
        }

        while(!s.empty()){
            ans *= 10;
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};