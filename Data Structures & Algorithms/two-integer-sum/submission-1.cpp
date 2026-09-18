class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_index;
        int complement;
        for (int i{}; i < nums.size(); ++i){
            complement = target - nums[i];
            if (num_index.contains(complement)){
                return {num_index[complement], i};
            }
            num_index.insert({nums[i], i});
        }
        return{};
    }
};
