class Solution {
public:
    int trap(vector<int>& height) {
        int left{};
        int right{static_cast<int>(height.size() - 1)};
        int rightmax{height[right]};
        int leftmax{height[left]};
        int water{};
        while (right > left){
            if (height[left] < height[right]){
                left++;
                water += (std::min(rightmax, leftmax) - height[left] > 0) ? std::min(rightmax, leftmax) - height[left] : 0;
                if (height[left] > leftmax) leftmax = height[left];
            } else {
                right --;
                water += (std::min(rightmax, leftmax) - height[right] > 0) ? std::min(rightmax, leftmax) - height[right] : 0;
                if (height[right] > rightmax) rightmax = height[right];
            }
        }
        return water;
    }
};
