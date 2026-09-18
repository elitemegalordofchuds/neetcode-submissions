class Solution {
public:
    bool isPalindrome(string s) {
        std::erase_if(s, [] (char c){
            return !std::isalnum(c) || std::isspace(c);
        });
        std::transform(s.begin(), s.end(), s.begin(), [] (char c){
            return std::tolower(c);
        });
        auto l{s.length()};
        if (l % 2 == 0){
            for (std::size_t j{}; j < l/2; ++j){
                if (s[l/2 - j - 1] != s[l/2 + j])
                    return false;
            }
            return true;
        } else {
            for (std::size_t j{}; j <= l/2; ++j){
                if (s[l/2 - j] != s[l/2 + j])
                    return false;
            }
            return true;
        }
    }
};
