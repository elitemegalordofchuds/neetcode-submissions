class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right{static_cast<int>(heights.size() - 1)};
        int left{};
        int max{};
        int area{};
        while (right > left){
            area = std::min(heights[left], heights[right]) * (right - left);
            if (area > max) max = area;
            if (heights[left] > heights[right]) right--;
            else left++;
        }
        return max;
    }
};
