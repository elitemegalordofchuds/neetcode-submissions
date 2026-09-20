class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return{};
        int right{};
        int left{};
        int minlength{};
        int required{};
        int formed{};
        int minleft{};
        std::vector<int> target(128);
        std::vector<int> window(128);
        for (char c : t) target[c]++;
        for (int count : target) if (count > 0) required++;
        
        // 1. Get initial window
        while (right < s.length()){
            char c = s[right];
            window[c]++;
            if (window[c] == target[c]) formed++;
            if (formed == required) break;
            right++;
        }
        if (formed != required) return{};

        // 2. Shrink initial window safely
        while (left <= right){
            char c = s[left];
            window[c]--;
            if (window[c] < target[c]) {
                window[c]++; // Revert so it stays valid
                break;
            }
            left++;
        }

        minlength = right - left + 1;
        minleft = left;

        // 3. Fixed Window Slide Phase
        while (right < s.length() - 1){
            // Instead of blindly dropping left, we always slide right first
            right++;
            window[s[right]]++;
            if (window[s[right]] == target[s[right]]) formed++;
            
            // Now that we added a character, check if we can slide left along with it
            // or shrink it even further if it's super optimized
            while (formed == required){  
                if (right - left + 1 < minlength) {
                    minlength = right - left + 1;
                    minleft = left;
                }
                char cl = s[left];
                window[cl]--;          
                if (window[cl] < target[cl]){
                    formed--; 
                }
                left++;
            }
        }
        return s.substr(minleft, minlength);
    }
};
