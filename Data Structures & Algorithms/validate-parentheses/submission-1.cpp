class Solution {
public:
    bool isValid(string s) {
        std::stack<char> open{};
        std::unordered_map<char, char> closing{{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s){
            if (closing.contains(c)){
                if (open.empty()){
                    return false;
                } else {
                    if (open.top() == closing[c]){
                        open.pop();
                    } else return false;
                }
            } else {
                open.push(c);
            }
        }
        return open.empty();
    }
};
