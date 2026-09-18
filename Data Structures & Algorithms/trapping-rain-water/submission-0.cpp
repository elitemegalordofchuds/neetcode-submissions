class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> rightmax{0};
        std::vector<int> leftmax{0};
        int size{static_cast<int>(height.size())};
        int max{};
        int current{};
        int water{};
        for (int i{}; i < size; ++i){
            if (height[i] > max){
                max = height[i];
            }
            leftmax.push_back(max);
        }
        max = 0;
        for (int i {size - 1}; i >= 0; --i){
            if (height[i] > max){
                max = height[i];
            }
            rightmax.push_back(max);
        }
        for (int i{}; i < height.size(); ++i){
            current = std::min(rightmax[height.size() - 1 - i], leftmax[i]);
            if (current - height[i] > 0){
                water += current - height[i];
            }
        }
        return water;
    }
};
