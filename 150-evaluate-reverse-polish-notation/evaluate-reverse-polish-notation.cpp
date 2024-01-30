class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const auto& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();

                if (c == "+") {
                    s.push(x + y);
                } else if (c == "-") {
                    s.push(x - y);
                } else if (c == "*") {
                    s.push(x * y);
                } else if (c == "/") {
                    s.push(x / y);  
                }
            } else {
                s.push(stoi(c));
            }
        }

        return s.top();
    }
};
