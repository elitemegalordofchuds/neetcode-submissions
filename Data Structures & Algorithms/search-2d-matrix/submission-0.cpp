class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left{};
        int right{static_cast<int>(matrix.size() * matrix[0].size() - 1)};
        int m{};
        int rowsize{static_cast<int>(matrix[0].size())};
        int i{};
        int j{};
        while (left <= right){
            m = left + (right - left) / 2;
            i = m / rowsize;
            j = m % rowsize;
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) left = m + 1;
            else right = m - 1;
        }
        return false;
    }
};
