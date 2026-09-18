class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<std::string>> key_arr;
        for (const auto& str : strs){
            std::vector<int> letter_freq(26);
            for (int i{}; i < str.length(); ++i){
                letter_freq[str[i]-97]++;
            }
            std::string key = std::to_string(letter_freq[0]);
            for (int i{1}; i < 26 ; ++i){
                key += "," + std::to_string(letter_freq[i]);
            }
            key_arr[key].push_back(str);
        }
        std::vector<std::vector<std::string>> res{};
        for (const auto& [key, arr] : key_arr){
            res.push_back(arr);
        }
        return res;
    }
};
