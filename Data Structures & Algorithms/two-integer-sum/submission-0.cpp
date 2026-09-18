class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> i_val;
        for (int i{}; i < nums.size(); ++i){
            int complement = target - nums[i];
            for (const auto& [index, val] : i_val){
                if (val == complement)
                    return {index, i};
            }
            i_val[i] = nums[i];
        }
    }
};
