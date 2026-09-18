class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (size_t i{}; i < nums.size(); ++i){
            if (m.count(nums[i]) > 0)
                return true;
            m.insert(nums[i]);
        }
        return false;
    }
};