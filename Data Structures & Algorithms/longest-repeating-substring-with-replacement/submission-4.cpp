class Solution {
public:
    int characterReplacement(string s, int k) {
        int left{};
        int right{};
        char current{};
        int max{};
        int length{};
        int gaps{};
        for (int i{65}; i < 91; ++i){
            length = right = left = gaps = 0;
            while (right < s.length()){
                if (s[right] != i){
                    gaps++;
                }
                while (gaps > k){
                    if (s[left] != i) gaps--;
                    left++;
                    length--;
                }
                right++;
                length++;
                max = std::max(max, length);
            }
        }
        return std::min(max, static_cast<int>(s.length()));
    }
};
