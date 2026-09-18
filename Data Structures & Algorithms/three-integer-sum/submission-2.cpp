class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> triplets{};
        int left{};
        int right{};
        int i{};
        while (i < nums.size() - 2){
            right = static_cast<int>(nums.size() - 1);
            left = i + 1;

            while (right > left){
                if (nums[right] + nums[left] + nums[i] > 0){
                    right--;
                } else if (nums[right] + nums[left] + nums[i] < 0) {
                    left++;
                } else {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (right > left && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while (right > left && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
            while(nums[i] == nums[i+1] && i < nums.size() - 2){
                i++;
            }
            i++;
        }
        return triplets;
    }
};
