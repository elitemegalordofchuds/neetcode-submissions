class Solution{
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return{};
        int right{};
        int left{};
        int minlength{INT_MAX};
        int required{};
        int formed{};
        int minleft{};
        std::vector<int> target(128);
        std::vector<int> window(128);
        for (char c : t) target[c]++;
        for (int count : target) if (count > 0) required++;

        while (right < s.length()){
            window[s[right]]++;
            if (window[s[right]] == target[s[right]]) formed++;
            
            while (formed == required){  
                if (minlength > right - left + 1){
                    minlength = right - left + 1;
                    minleft = left;
                }
                char cl = s[left];          
                if (window[cl] == target[cl]) formed--;
                window[cl]--;
                left++;
            }
            right++;
        }
        return (minlength == INT_MAX)? "" : s.substr(minleft, minlength);
    }
};
