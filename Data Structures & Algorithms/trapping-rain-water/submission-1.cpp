class Solution {
public:
    int trap(vector<int>& height) {
        int right{static_cast<int>(height.size() - 1)};
        int left{};
        int leftmax{height[left]};
        int rightmax{height[right]};
        int water{};
        while (left < right){
            if (leftmax < rightmax){
                left++;
                leftmax = std::max(leftmax, height[left]);
                water += leftmax - height[left];
            } else {
                right--;
                rightmax = std::max(rightmax, height[right]);
                water += rightmax - height[right];
            }
        }
        return water;
    }
};
