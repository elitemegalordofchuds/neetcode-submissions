class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> arr(nums.size()+1);
        unordered_map<int, int> int_freq;
        for (int num : nums){
            int_freq[num]++;
        }
        for (const auto& [num, freq] : int_freq){
            arr[freq].push_back(num);
        }
        vector<int> res;
        for (size_t i{arr.size()-1}; i >= 0; --i){
            for (int num : arr[i]){
                res.push_back(num);
            }
            if (res.size() == k)
                return res;
        }
    }
};
