class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> chars{};
        for (const auto& c : s1) {
            chars[c]++;
        }
        std::unordered_map<char, int> current{};
        int left{};
        int right{};
        int length{};
        for (int right{}; right < s2.length(); ++right) {
            if (!chars.contains(s2[right])) {
                left = right + 1;
                current = {};
                continue;
            }
            if (current.contains(s2[right]) && current[s2[right]] == chars[s2[right]]) {
                while (s2[left] != s2[right]){
                    current[s2[left]]--;
                    left++;
                }
                left++;
            } else {
                current[s2[right]]++;
            }
            length = right - left + 1;
            if (length == s1.length()) return true;
        }
        return false;
    }
};
