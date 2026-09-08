class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Top element is the right operand
                int y = s.top();
                s.pop();

                int x = s.top();
                s.pop();

                if (token == "+") s.push(x + y);
                else if (token == "-") s.push(x - y);
                else if (token == "*") s.push(x * y);
                else if (token == "/") s.push(x / y);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};