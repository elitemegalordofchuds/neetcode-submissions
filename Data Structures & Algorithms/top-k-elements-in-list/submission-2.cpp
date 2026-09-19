class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res{};
        if (nums.size() == 1){
            res.push_back(nums[0]);
            return res;
        };
        int size{static_cast<int>(nums.size())};
        std::vector<std::vector<int>> freq_nums(size + 1);
        std::unordered_map<int, int> num_freq{};
        for (int i{}; i < nums.size(); ++i){
            num_freq[nums[i]]++;
        }
        for (const auto& numfreq : num_freq){
            freq_nums[numfreq.second].push_back(numfreq.first);
        }
        for (int i{size}; i >= 0; --i){
            for (int j{}; j < freq_nums[i].size(); ++j){
                res.push_back(freq_nums[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
