class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> num{};
        for (int i{}; i < nums.size(); ++i){
            if (num.contains(nums[i])){
                return true;
            } else {
                num.insert(nums[i]);
            }
        }
        return false;
    }
};