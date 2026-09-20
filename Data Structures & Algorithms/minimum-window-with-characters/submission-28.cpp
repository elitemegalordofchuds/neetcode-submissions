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
        
        while (right < s.length()){
            char c = s[right];
            window[c]++;
            if (window[c] == target[c]) formed++;
            if (formed == required) break;
            right++;
        }
        if (formed != required) return{};

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

        while (right < s.length() - 1){
            char cl_out = s[left];
            if (window[cl_out] == target[cl_out]) formed--;
            window[cl_out]--;
            left++; // Left moves exactly 1 step
            
            right++;
            window[s[right]]++;
            if (window[s[right]] == target[s[right]]) formed++;
            
            while (formed == required){  
                minlength = right - left + 1;
                minleft = left;
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
