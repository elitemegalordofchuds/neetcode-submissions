class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        int m{};
        if (nums[r] < nums[l]){ //rotated
            while (r > l + 1){
                m = l + (r - l) / 2;
                if (nums[m] > nums[l]) l = m;
                if (nums[m] < nums[l]) r = m;
            }
            if (target > nums[nums.size() - 1]){ //in lower interval
                r = l;
                l = 0;
            } else { //in higher interval
                l = r;
                r = nums.size() - 1;
            }
        }
        while (l <= r){ //usual search
            m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
