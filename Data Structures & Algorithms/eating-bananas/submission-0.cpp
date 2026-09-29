class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max{};
        for (const auto& p : piles) max = std::max(max, p);
        int left{1};
        int right{max};
        int minrate{max};
        while (left <= right){
            int m = left + (right - left) / 2;
            long long hours = 0;
            for (const auto& p : piles){
                hours += p / m;
                if (p % m != 0) hours++;
            }
            if (hours <= h){
            minrate = m; 
            right = m - 1;
            }
            else left = m + 1;
        }
        return minrate;
    }
};
