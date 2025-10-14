class Solution {
public:
    // Operator precedence
    int precedence(char op) {
        switch(op) {
            case '^': return 3;
            case '*': case '/': return 2;
            case '+': case '-': return 1;
            default: return 0;
        }
    }

    // Apply operator to two operands
    long long applyOp(long long a, long long b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b; // assumes b != 0
            case '^': return pow(a, b);
        }
        return 0;
    }

    // Evaluate infix expression
    long long calculate(string s) {
        stack<long long> values;
        stack<char> ops;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            char c = s[i];

            // Skip spaces
            if(c == ' ') continue;

            // If number: parse full number (multi-digit)
            if(isdigit(c)) {
                long long val = 0;
                while(i < n && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--; // adjust for extra increment
                values.push(val);
            }
            // Opening parenthesis
            else if(c == '(') {
                ops.push(c);
            }
            // Closing parenthesis
            else if(c == ')') {
                while(!ops.empty() && ops.top() != '(') {
                    long long val2 = values.top(); values.pop();
                    long long val1 = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                if(!ops.empty()) ops.pop(); // pop '('
            }
            // Operator
            else {
                while(!ops.empty() && 
                      ((precedence(ops.top()) > precedence(c)) || 
                       (precedence(ops.top()) == precedence(c) && c != '^'))) {
                    long long val2 = values.top(); values.pop();
                    long long val1 = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(c);
            }
        }

        // Apply remaining operators
        while(!ops.empty()) {
            long long val2 = values.top(); values.pop();
            long long val1 = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(val1, val2, op));
        }

        return values.top();
    }
};