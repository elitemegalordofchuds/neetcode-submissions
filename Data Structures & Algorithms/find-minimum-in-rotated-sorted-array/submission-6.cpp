class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::min(nums[0], nums[1]);
        int left{};
        int right = nums.size() - 1;
        int mid{};
        while (right > left + 1){
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) right = mid;
            if (nums[mid] > nums[left]) left = mid;
        }
        if (nums[right] > nums[left]) return nums[0];
        else return nums[left + 1];
    }
};
