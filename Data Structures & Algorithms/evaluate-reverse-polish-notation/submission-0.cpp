class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> mystack{};
        for (const auto& t : tokens){
            int val{};
            auto [ptr, ec] = std::from_chars(t.data(), t.data() + t.size(), val);
            if (ec == std::errc{}){
                mystack.push(val);
            } else {
                int b = mystack.top(); mystack.pop();
                int a = mystack.top(); mystack.pop();

                if (t == "+") mystack.push(a + b);
                if (t == "-") mystack.push(a - b);
                if (t == "*") mystack.push(a * b);
                if (t == "/") mystack.push(a / b);
            }
        }
        return mystack.top();
    }
};
