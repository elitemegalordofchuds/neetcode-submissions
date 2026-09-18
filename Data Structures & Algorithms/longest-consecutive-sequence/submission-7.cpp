class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return {};
        }
        std::unordered_set<int> numbers;
        int count{1};
        int maxcount {1};
        int j{1};
        for (int i{}; i < nums.size(); ++i){
            numbers.insert(nums[i]);
        }
        for (const auto& num : nums){
            if (!numbers.contains(num - 1)){
                while (numbers.contains(num+j)){
                    count++;
                    j++;
                }
            }
            if (count > maxcount){
                maxcount = count;
            }
            count = 1;
            j = 1;
        }
        return maxcount;
    }
};
