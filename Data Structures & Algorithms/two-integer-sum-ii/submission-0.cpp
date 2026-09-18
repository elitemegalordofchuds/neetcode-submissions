class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin{};
        int end{static_cast<int>(numbers.size() - 1)};
        int tot{};
        while(begin != end){
            tot = numbers[begin] + numbers[end];
            if (tot == target)
                return {begin + 1, end + 1};
            else if (tot < target){
                begin++;
            } else {
                end--;
            }
        }
        return {};
    }
};
