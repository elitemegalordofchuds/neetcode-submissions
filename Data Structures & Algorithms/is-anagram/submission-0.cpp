class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> Smap;
        for (int i{}; i < s.length(); ++i){
            Smap[s[i]]++;
            Smap[t[i]]--;
        }
        for (const auto& [car, freq] : Smap){
            if (freq != 0){
                return false;
            }
        }
        return true;
    }
};
