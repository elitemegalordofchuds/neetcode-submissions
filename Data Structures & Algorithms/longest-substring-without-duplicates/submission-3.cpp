class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1){
            return 1;
        }
        std::unordered_map<int, int> char_index{};
        int left{};
        int right{};
        int length{};
        int maxlength{};
        while (right < s.length()){
            if (char_index.contains(s[right]) && char_index[s[right]] >= left){
                while (left <= char_index[s[right]]){
                    left++;
                }
            }                
            length = right - left + 1;
            maxlength = std::max(length, maxlength);
            char_index[s[right]] = right;
            right++;
        }
        return maxlength;
    }
};
