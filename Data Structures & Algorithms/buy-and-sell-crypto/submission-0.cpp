class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy{prices[0]};
        int maxprofit{};
        for (int i{1}; i < prices.size(); ++i){
            maxprofit = std::max(maxprofit, prices[i] - minbuy);
            minbuy = std::min(minbuy, prices[i]);
        }
        return maxprofit;
    }
};
