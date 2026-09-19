class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> key_vec{};
        char current{};
        std::string key{};
        for (int i{}; i < strs.size(); ++i){
            std::vector<int> char_freq(26);
            for (int j{}; j < strs[i].length(); ++j){
                current = std::tolower(strs[i][j]);
                char_freq[current - 'a']++;
            }
            key = char_freq[0];
            for (int i{1}; i < char_freq.size(); ++i){
                key += ',' + char_freq[i];
            }
            key_vec[key].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> vecvec{};
        for (const auto& s : key_vec){
            vecvec.push_back(s.second);
        }
        return vecvec;
    }
};
