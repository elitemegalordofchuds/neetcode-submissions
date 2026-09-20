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
        
        // 1. Find initial valid window
        while (right < s.length()){
            char c = s[right];
            window[c]++;
            if (window[c] == target[c]) formed++;
            if (formed == required) break;
            right++;
        }
        if (formed != required) return{};

        // 2. Shrink initial window to find the minimum fixed size
        while (left <= right){
            char c = s[left];
            window[c]--;
            if (window[c] < target[c]) {
                window[c]++; // Keep it valid
                break;
            }
            left++;
        }

        minlength = right - left + 1;
        minleft = left;

        // 3. Strict Fixed-Size Window Slide Phase
        while (right < s.length() - 1){
            // Slide Left: Drop the outgoing character
            char cl_out = s[left];
            if (window[cl_out] == target[cl_out]) formed--;
            window[cl_out]--;
            left++; // Left moves exactly 1 step

            // Slide Right: Add the incoming character
            right++; // Right moves exactly 1 step
            char cr_in = s[right];
            window[cr_in]++;
            if (window[cr_in] == target[cr_in]) formed++;
            
            // If the fixed window becomes valid again, try to shrink it even smaller
            while (formed == required){  
                if (right - left + 1 < minlength) {
                    minlength = right - left + 1;
                    minleft = left;
                }
                char cl_shrink = s[left];
                window[cl_shrink]--;          
                if (window[cl_shrink] < target[cl_shrink]){
                    formed--; 
                }
                left++;
            }
        }
        return s.substr(minleft, minlength);
    }
};
