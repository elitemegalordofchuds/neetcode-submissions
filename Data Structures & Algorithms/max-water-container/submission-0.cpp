class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right = static_cast<int>(heights.size() - 1);
        int left = 0;
        int height{};
        int area{};
        int res{};
        while (right > left){
            height = std::min(heights[left], heights[right]);
            area = height * (right - left);
            res = std::max(area, res);
            if (heights[right] < heights[left]){
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};
