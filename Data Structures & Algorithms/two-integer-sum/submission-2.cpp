class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int complement{};
        std::unordered_map<int, int> num_index{};
        for (int i{}; i < nums.size(); ++i){
            complement = target - nums[i];
            if (num_index.contains(complement)) return {std::min(num_index[complement], i), std::max(num_index[complement], i)};
            num_index[nums[i]] = i;
        }
    }
};
