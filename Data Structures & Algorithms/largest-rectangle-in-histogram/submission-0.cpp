class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> i_height{};
        int max{};
        int start{};
        for (int i {}; i < heights.size(); ++i){
            start = i;
            while (!i_height.empty() and i_height.top().second > heights[i]){
                max = std::max(max, i_height.top().second * (i - i_height.top().first));
                start = i_height.top().first;
                i_height.pop();
            }
            if (i_height.empty()){
                i_height.push({0, heights[i]});
            } else {
                i_height.push({start, heights[i]});
            }
        }
        while (!i_height.empty()){
            max = std::max(max, i_height.top().second * (static_cast<int> (heights.size()) - i_height.top().first));
            i_height.pop();
        }
        return max;
    }
};
