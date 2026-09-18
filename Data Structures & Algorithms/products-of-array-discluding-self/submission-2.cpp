class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output;
        int prod{1};
        int count{};
        std::bitset<3> one_more_all(0b01);
        for (int i{}; i < nums.size(); ++i){
            if (nums[i] != 0){
                one_more_all.reset(0);
                prod *= nums[i];
            }
            else{
                count++;
            }
        }
        if (count > 1){
            one_more_all.set(1);
        } else  if (count == 1){
            one_more_all.set(2);
        }
        if (one_more_all[0] || one_more_all[1]){
            for (int i{}; i < nums.size(); ++i){
                output.push_back(0);
            }
            return output;
        }
        for (int i{}; i < nums.size(); ++i){
            if (one_more_all[2]){
                if (nums[i] == 0){
                    output.push_back(prod);
                }
                else{
                    output.push_back(0);
                }
            }
            else{
                output.push_back(prod/nums[i]);
            }
        }
        return output;
    }
};
