class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, float>> times{};
        for (int i{}; i < position.size(); ++i){
            times.push_back({position[i], (static_cast<double>(target) - position[i]) / speed[i]});
        }
        std::sort(times.rbegin(), times.rend());
        int count{1};
        float maxtime{times[0].second};
        for (int i{1}; i < times.size(); ++i){
            if (maxtime < times[i].second){
                count++;
                maxtime = times[i].second;
            }
        }
        return count;
    }
};
