class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<char, int> char_freq1{};
        std::unordered_map<char, int> char_freq2{};
        for (int i{}; i < s.length(); ++i){
            char_freq1[s[i]]++;
            char_freq2[t[i]]++;
        }
        return char_freq1 == char_freq2;
    }
};
